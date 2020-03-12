#ifndef KIMERA_ROS__INTERFACES__BASE_INTERFACE_HPP_
#define KIMERA_ROS__INTERFACES__BASE_INTERFACE_HPP_

#include <future>

#include "glog/logging.h"
#include "kimera-vio/dataprovider/DataProviderInterface.h"
#include "kimera-vio/pipeline/Pipeline.h"
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/transform_listener.h"

namespace kimera_vio_ros
{
namespace interfaces
{

class BaseInterface : public VIO::DataProviderInterface
{
public:
  BaseInterface(
    rclcpp::Node::SharedPtr & node);
  virtual ~BaseInterface();
  void start();

protected:
  rclcpp::Node::SharedPtr node_;
  VIO::Pipeline::Ptr pipeline_;

  std::string base_link_frame_id_;
  std::string map_frame_id_;
  std::string world_frame_id_;

  std::shared_ptr<tf2_ros::Buffer> buffer_;
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

private:
  rclcpp::callback_group::CallbackGroup::SharedPtr callback_group_pipeline_;
  rclcpp::TimerBase::SharedPtr pipeline_timer_;
  std::future<bool> handle_pipeline_;
};

}  // namespace interfaces
}  // namespace kimera_vio_ros

#endif  // KIMERA_ROS__INTERFACES__BASE_INTERFACE_HPP_
