#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MinimalSubscriber : public rclcpp::Node {
 private:
  /* data */
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

  /* methods */
  void topic_callback(const std_msgs::msg::String& msg) const;

 public:
  MinimalSubscriber(/* args */);
  ~MinimalSubscriber();
};