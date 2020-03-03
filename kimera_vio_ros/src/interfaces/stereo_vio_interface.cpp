#include "kimera_vio_ros/interfaces/stereo_vio_interface.hpp"

namespace kimera_vio_ros
{
namespace interfaces
{

StereoVioInterface::StereoVioInterface(
  rclcpp::Node::SharedPtr & node)
: BaseInterface(node),
  ImageInterface(node),
  ImuInterface(node),
  StereoInterface(node),
  BackendInterface(node)
{
  BaseInterface::start();
}

StereoVioInterface::~StereoVioInterface()
{
}

}  // namespace interfaces
}  // namespace kimera_vio_ros
