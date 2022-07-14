//
// Created by ljq on 2022/7/14.
//
#include "rm_manual/reversal_manual.h"

namespace rm_manual
{
ReversalManual::ReversalManual(ros::NodeHandle& nh) : ManualBase(nh)
{
  ros::NodeHandle reversal_nh(nh, "reversal");
  reversal_cmd_sender_ = new rm_common::ReversalCommandSender(reversal_nh);
}

void ReversalManual::sendCommand(const ros::Time& time)
{
  reversal_cmd_sender_->sendCommand(time);
}
void ReversalManual::updateRc()
{
  ManualBase::updateRc();
  scales_[0] = data_.dbus_data_.ch_r_x;
  scales_[1] = data_.dbus_data_.ch_l_x;
  reversal_cmd_sender_->setLinearVel(scales_[0], scales_[1]);
}

void ReversalManual::remoteControlTurnOff()
{
  ManualBase::remoteControlTurnOff();
  reversal_cmd_sender_->setZero();
}
}  // namespace rm_manual
