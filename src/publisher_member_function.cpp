#include "cpp_pubsub/publisher_member_funcion.hpp"

using namespace std::chrono_literals;

MinimalPublisher::MinimalPublisher(/* args */)
    : Node("minimal_publisher"),
      count_(0),
      publisher_(create_publisher<std_msgs::msg::String>("topic", 10)),
      timer_(create_wall_timer(
          500ms, std::bind(&MinimalPublisher::timer_callback, this))) {}

MinimalPublisher::~MinimalPublisher() {}

void MinimalPublisher::timer_callback() {
  auto message = std_msgs::msg::String();
  message.data = "Hello World! " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}