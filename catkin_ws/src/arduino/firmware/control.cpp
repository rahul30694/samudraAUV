// http://wiki.ros.org/rosserial_arduino/Tutorials/CMake
#include <ros.h>
#include <geometry_msgs/Pose2D.h>
#include <sensor_msgs/Imu.h>
#include <Arduino.h>
// When you are compiling a cpp file outside of the Arduino IDE, you need to explicitly 
// include a header file which contains all of the Arduino functions (digitalRead, analogRead, delay, etc.).

double  ox,oy,oz; //orientation ke x,y,z. These are made global so that they will be automatically be updated via ROS callback functions
double lax,lay,laz; //Linear Acceleration in x, and z similarly.
double avx,avy,avz; //Angular velocity x,y,z
double x,y,theta; //Heading Parameters
double xt,yt,thetat; //TrueHeading Parameters

void updateData(const sensor_msgs::Imu& msg)
{
    //Orientation,LA and AV would be updated :)
    ox = msg.orientation.x;
    oy = msg.orientation.y;
    oz = msg.orientation.z;
    
    lax = msg.linear_acceleration.x;
    lay = msg.linear_acceleration.y;
    laz = msg.linear_acceleration.z;
    
    avx = msg.angular_velocity.x;
    avy = msg.angular_velocity.y;
    avz = msg.angular_velocity.z;
  
    //ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void updateHeading(const geometry_msgs::Pose2D& msg)
{
    x = msg.x;
    y = msg.y;
    theta = msg.theta;
}

void updateHeadingTrueDegree(const geometry_msgs::Pose2D& msg)
{
    xt = msg.x;
    yt = msg.y;
    thetat = msg.theta;
}

ros::NodeHandle n;
ros::Subscriber<sensor_msgs::Imu> s1("imu/data", updateData );
ros::Subscriber<geometry_msgs::Pose2D> s2("imu/HeadingTrue", updateHeading );
ros::Subscriber<geometry_msgs::Pose2D> s3("imu/HeadingTrue_degree", updateHeadingTrueDegree );

void setup()
{
  //pinMode(13, OUTPUT); Initialize all the pinModes here
  n.initNode();
  n.subscribe(s1);
  n.subscribe(s2);
  n.subscribe(s3);
}
void loop()
{

  /*
  Serial.print(ox); 
  Serial.print(" ");
  Serial.print(oy);
  Serial.print(" ");
  Serial.print(oz);
  Serial.print(" ");
  
  Serial.print(lax);
  Serial.print(" ");
  Serial.print(lay);
  Serial.print(" ");
  Serial.print(laz);
  Serial.print(" ");
  
  
  Serial.print(avx);
  Serial.print(" ");
  Serial.print(avy);
  Serial.print(" ");
  Serial.print(avz);
  Serial.print(" ");
  
  
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(theta);
  Serial.print(" ");
  
  Serial.print("\n");
  */

  n.spinOnce();
}
