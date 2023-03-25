#include <chrono>
#include <functional>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

class MinimalPublisher : public rclcpp::Node {
 private:
  /* data */
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  /* methods */
  void timer_callback();

 public:
  MinimalPublisher(/* args */);
  ~MinimalPublisher();
};