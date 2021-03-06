#include "mainwindow.h"
#include <QApplication>
#include "globals.h"
#include "mat_and_qimage.hpp"
#include "ros/ros.h"
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

# ifndef QStringLiteral
# define QStringLiteral(str) QString::fromUtf8("" str "", sizeof(str) - 1)
# endif

# ifndef QByteArrayLiteral
# define QByteArrayLiteral(str) QByteArray(str, sizeof(str) - 1)
# endif

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
   {
     try
     {
       cur_frame =  cv_bridge::toCvShare(msg, "bgr8")->image;
       cv::imshow("view",cur_frame);
       img = ocv::qt::mat_to_qimage_cpy(cur_frame,true);//Convert Mat->QImage and pass true for swapping channels(BGR->RGB)  
       cv::waitKey(30);
     }
     catch (cv_bridge::Exception& e)
     {
       ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
     }
   }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "QT");
  n = new ros::NodeHandle();
  image_transport::ImageTransport it(*n);  	
  image_transport::Subscriber sub = it.subscribe("camera/image_raw", 1,imageCallback);
  QApplication app(argc, argv);
  MainWindow w;
  w.show();
  //ros::Rate loop_rate(5);
  int count = 0;
  while (ros::ok())
  {
    app.processEvents();
    ros::spinOnce();  
    //loop_rate.sleep();
    count++; //Optionally for debugging..to keep a track of sent messages
  }
  return app.exec();
}
