/**
 * @file led_task.cpp
 * @brief LED控制led流水灯文件
 * @author YuZixuan
 * @date 2024-09-28
 */
#include "cmsis_os.h"
#include "io/led/led.hpp"
constexpr uint8_t LED_FADE_STEPS = 10;//led渐变步数
constexpr uint16_t LED_FADE_DELAY_MS = 100;//led渐变延迟时间
constexpr float LED_BRIGHTNESS_STEP = 0.01f;//led亮度步进值
/**
 * @brief LED控制任务主函数
 * @note 实现LED呼吸灯效果，绿色通道从0%到10%渐变
 */
extern "C" void led_task()
{
  sp::LED led(&htim5);
  led.start();

   while (true) {
    // 亮度渐增：0% → 10%
    for (uint8_t brightness = 0; brightness < LED_FADE_STEPS; brightness++) {
      led.set(0, brightness * LED_BRIGHTNESS_STEP, 0);
      osDelay(LED_FADE_DELAY_MS);
    }

        // 亮度渐减：10% → 0%
    for (uint8_t brightness = LED_FADE_STEPS; brightness > 0; brightness--) {
      led.set(0, brightness * LED_BRIGHTNESS_STEP, 0);
      osDelay(LED_FADE_DELAY_MS);
    }
  }
}