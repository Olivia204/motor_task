/**
 * @file buzzer_task.cpp
 * @brief 蜂鸣器控制任务实现文件
 * @author YuZixuan
 * @date 2024-09-28
 */
#include "cmsis_os.h"
#include "io/buzzer/buzzer.hpp"
sp::Buzzer buzzer(&htim4, TIM_CHANNEL_3, 84e6);// 蜂鸣器硬件配置：使用TIM4通道3，84MHz时钟
/**
 * @brief 蜂鸣器任务入口函数
 */
extern "C" void buzzer_task()
{
  buzzer.set(5000, 0.1);// 初始化蜂鸣器参数频率5000Hz，占空比10%

  for (int i = 0; i < 1; i++) {//蜂鸣三次提示音
    buzzer.start();
    osDelay(100);//任务延迟时间为100ms
    buzzer.stop();
    osDelay(100);
  }

  while (true) {// 主任务循环
    osDelay(100);
  }
}