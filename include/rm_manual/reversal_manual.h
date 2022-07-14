//
// Created by ljq on 2022/7/14.
//

#pragma once

#include "rm_manual/common/manual_base.h"
#include "rm_common/decision/command_sender.h"
namespace rm_manual
{
class ReversalManual : public ManualBase
{
public:
  explicit ReversalManual(ros::NodeHandle& nh);

protected:
  void sendCommand(const ros::Time& time) override;
  void updateRc() override;
  void remoteControlTurnOff() override;

  rm_common::ReversalCommandSender* reversal_cmd_sender_{};
  double scales_[2];
};
}  // namespace rm_manual
