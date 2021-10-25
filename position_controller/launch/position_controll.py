from  launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='position_controller',
            node_namespace='position_controller',
            node_executable='position_controller',
            node_name='position_controller'
        ),
        Node(
            package='position_controller',
            node_namespace='position_controller',
            node_executable='pianificatore',
            node_name='pianificatore'
        )
    ])
