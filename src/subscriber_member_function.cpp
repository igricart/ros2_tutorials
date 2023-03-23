#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using std::placeholders::_1;

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

MinimalSubscriber::MinimalSubscriber(/* args */)
    : Node("minimal_susbscriber"),
      subscription_(create_subscription<std_msgs::msg::String>(
          "topic", 10,
          std::bind(&MinimalSubscriber::topic_callback, this, _1))) {}

MinimalSubscriber::~MinimalSubscriber() {}

void MinimalSubscriber::topic_callback(const std_msgs::msg::String& msg) const {
  RCLCPP_INFO(this->get_logger(), "I heard '%s'", msg.data.c_str());
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}