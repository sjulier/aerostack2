// Copyright 2024 Universidad Politécnica de Madrid
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the Universidad Politécnica de Madrid nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


/*
 * Copyright (C) 2022 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef MBZIRC_IGN_SUCTIONGRIPPER_HH_
#define MBZIRC_IGN_SUCTIONGRIPPER_HH_

#include <memory>
#include <gz/gazebo/System.hh>

namespace mbzirc
{
  class SuctionGripperPrivate;

////////////////////////////////////////////////////
/// \brief This plugin implements a suction gripper.
/// When the gripper makes contact with an item it picks up the item.
/// One can command the release of the item through a configurable topic.
/// The plugin requires a contact sensor to detect when an item is in contact.
///
/// # Parameters
/// <parent_link>
/// The link to which this gripper should be attached. [string]
/// <contact_sensor_topic>
/// The topic to listen to for contact sensor inputs. [string]
/// <command_topic>
/// The topic to listen to for commands. [string]
///
/// # Subscribers
/// <contact_sensor_topic> used to detect when an item is in
/// contact. [gz::msgs::Contacts]
/// <command_topic> - used to command the release of an item. Sending a False
/// to this topic will cause the suction to stop. If there is an object then
/// it will be released, otherwise new objects will not be picked up. Sending
/// a true signal again will cause the suction to start again. By default
/// suction is on. [igntion::msgs::Boolean]
  class SuctionGripperPlugin:
  public ignition::gazebo::System,
  public ignition::gazebo::ISystemConfigure,
  public ignition::gazebo::ISystemPreUpdate
  {
public:
    SuctionGripperPlugin();

public:
    ~SuctionGripperPlugin();

public:
    void Configure(
      const ignition::gazebo::Entity & _entity,
      const std::shared_ptr < const sdf::Element > & _sdf,
      ignition::gazebo::EntityComponentManager & _ecm,
      ignition::gazebo::EventManager & _eventMgr) override;

public:
    void PreUpdate(
      const ignition::gazebo::UpdateInfo & _info,
      ignition::gazebo::EntityComponentManager & _ecm) override;

public:
    std::unique_ptr < SuctionGripperPrivate > dataPtr;
  };
}

#endif
