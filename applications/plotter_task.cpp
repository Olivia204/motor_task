/**
 * @file plotter_task.cpp
 * @brief 电机状态获取任务实现文件
 * @author YuZixuan
 * @date 2024-09-28
 */
#include "cmsis_os.h"
#include "io/dbus/dbus.hpp"
#include "io/plotter/plotter.hpp"
#include "motor/rm_motor/rm_motor.hpp"

extern sp::DBus remote;// 遥控器对象，接收遥控器数据
extern sp::RM_Motor motor_6020;// RM 6020电机对象，控制电机并获取状态
sp::Plotter plotter(&huart1);

extern "C" void plotter_task()
{
  while (true) {
    plotter.plot(remote.ch_lh, motor_6020.speed);// 发送遥控器通道数据和电机转速数据
    osDelay(1);  // 100Hz
  }
}