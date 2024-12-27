import {
  ActivityIndicator,
  Alert,
  Image,
  Pressable,
  ScrollView,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
} from "react-native";
import sample_image from "../assets/sample_image.png";
import cart from "../assets/cart.png";
import qr_white from "../assets/qr_white.png";
import cart_white from "../assets/cart_white.png";
import map_sample from "../assets/map_sample.png";
import map from "../assets/map.png";
import location_white from "../assets/location_white.png";
import sample_image2 from "../assets/sample_image2.png";
import alert_yellow from "../assets/alert_yellow.png";
import robot_white from "../assets/robot_white.png";
import arrow_white from "../assets/arrow_white.png";
import { useEffect, useState } from "react";
import ROSLIB from "roslib";

let ros;

export default function Manual() {
  useEffect(() => {
    ros = new ROSLIB.Ros({
      //ros bridge server와 연동하기 위하여 어디로 접속할지
      url: "ws://192.168.0.101:9090",
    });

    // If there is an error on the backend, an 'error' emit will be emitted.
    ros.on("error", function (error) {
      console.log("Error connecting to websocket server: ", error);
    });

    // Find out exactly when we made a connection.
    ros.on("connection", function () {
      console.log("Connected to websocket server.");
    });

    ros.on("close", function () {
      console.log("Connection to websocket server closed.");
    });
  }, []); // []안에 있는 값이 바뀔 때 내용물 실행

  const leftPress = () => {
    console.log("leftPress");

    var LeftButton = new ROSLIB.Topic({
      ros: ros,
      name: "/cmd_vel", //"/i6robotics_navigation_server", //'/turtle1/teleport_absolute', //서비스 명
      messageType: "geometry_msgs/msg/Twist", //"i6robotics_control_msgs/srv/NavOrderSrv", //메시지타입
    });
    var msg = new ROSLIB.Message({
      linear: { x: 0.0, y: 0.0, z: 0.0 },
      angular: { x: 0.0, y: 0.0, z: 0.5 },
    });
    LeftButton.publish(msg);
  };

  const rightPress = () => {
    console.log("rightPress");

    var RightButton = new ROSLIB.Topic({
      ros: ros,
      name: "/cmd_vel", //"/i6robotics_navigation_server", //'/turtle1/teleport_absolute', //서비스 명
      messageType: "geometry_msgs/msg/Twist", //"i6robotics_control_msgs/srv/NavOrderSrv", //메시지타입
    });
    var msg = new ROSLIB.Message({
      linear: { x: 0.0, y: 0.0, z: 0.0 },
      angular: { x: 0.0, y: 0.0, z: -0.5 },
    });
    RightButton.publish(msg);
  };

  const forwardPress = () => {
    console.log("forwardPress");

    var ForwardButton = new ROSLIB.Topic({
      ros: ros,
      name: "/cmd_vel", //"/i6robotics_navigation_server", //'/turtle1/teleport_absolute', //서비스 명
      messageType: "geometry_msgs/msg/Twist", //"i6robotics_control_msgs/srv/NavOrderSrv", //메시지타입
    });
    var msg = new ROSLIB.Message({
      linear: { x: 0.2, y: 0.0, z: 0.0 },
      angular: { x: 0.0, y: 0.0, z: 0.0 },
    });
    ForwardButton.publish(msg);
  };

  const backwardPress = () => {
    console.log("backwardPress");

    var backwardButton = new ROSLIB.Topic({
      ros: ros,
      name: "/cmd_vel", //"/i6robotics_navigation_server", //'/turtle1/teleport_absolute', //서비스 명
      messageType: "geometry_msgs/msg/Twist", //"i6robotics_control_msgs/srv/NavOrderSrv", //메시지타입
    });
    var msg = new ROSLIB.Message({
      linear: { x: -0.2, y: 0.0, z: 0.0 },
      angular: { x: 0.0, y: 0.0, z: 0.0 },
    });
    backwardButton.publish(msg);
  };

  return (
    <View style={styles.container}>
      <View>
        <Text
          style={{
            fontSize: 20,
            fontWeight: 700,
            marginBottom: 16,
          }}
        >
          Manual Control for escape
        </Text>
        <Image
          style={{
            width: "100%",
            height: 200,
            marginBottom: 16,
            borderRadius: 4,
          }}
          source={sample_image2}
        />
        <View
          style={{
            paddingHorizontal: 24,
            paddingVertical: 16,
            backgroundColor: "white",
            flexDirection: "row",
            justifyContent: "center",
            alignItems: "center",
            gap: 8,
            borderRadius: 8,
            marginBottom: 16,
          }}
        >
          <Image source={alert_yellow} style={{ width: 14, height: 14 }} />
          <Text style={{ fontSize: 14, fontWeight: 500 }}>
            Emergency Manual Control Mode Activated
          </Text>
        </View>
        <View style={{ flexDirection: "row", justifyContent: "center" }}>
          <TouchableOpacity
            style={{
              backgroundColor: "#1B9AF5",
              width: 60,
              height: 60,
              borderRadius: 4,
              justifyContent: "center",
              alignItems: "center",
            }}
            onPress={forwardPress}
          >
            <Image
              source={arrow_white}
              style={{ width: 24, height: 24, objectFit: "contain" }}
            />
          </TouchableOpacity>
        </View>
        <View
          style={{ flexDirection: "row", justifyContent: "center", gap: 60 }}
        >
          <TouchableOpacity
            style={{
              backgroundColor: "#1B9AF5",
              width: 60,
              height: 60,
              borderRadius: 4,
              justifyContent: "center",
              alignItems: "center",
            }}
            onPress={leftPress}
          >
            <Image
              source={arrow_white}
              style={{
                width: 24,
                height: 24,
                objectFit: "contain",
                transform: [{ rotate: "270deg" }],
              }}
            />
          </TouchableOpacity>
          <TouchableOpacity
            style={{
              backgroundColor: "#1B9AF5",
              width: 60,
              height: 60,
              borderRadius: 4,
              justifyContent: "center",
              alignItems: "center",
            }}
            onPress={rightPress}
          >
            <Image
              source={arrow_white}
              style={{
                width: 24,
                height: 24,
                objectFit: "contain",
                transform: [{ rotate: "90deg" }],
              }}
            />
          </TouchableOpacity>
        </View>
        <View style={{ flexDirection: "row", justifyContent: "center" }}>
          <TouchableOpacity
            style={{
              backgroundColor: "#1B9AF5",
              width: 60,
              height: 60,
              borderRadius: 4,
              justifyContent: "center",
              alignItems: "center",
            }}
            onPress={backwardPress}
          >
            <Image
              source={arrow_white}
              style={{
                width: 24,
                height: 24,
                objectFit: "contain",
                transform: [{ rotate: "180deg" }],
              }}
            />
          </TouchableOpacity>
        </View>
      </View>
      <TouchableOpacity
        style={{
          paddingHorizontal: 24,
          paddingVertical: 12,
          backgroundColor: "#1B9AF5",
          flexDirection: "row",
          justifyContent: "center",
          alignItems: "center",
          gap: 8,
          borderRadius: 8,
        }}
      >
        <Image
          source={robot_white}
          style={{ width: 14, height: 14, objectFit: "contain" }}
        />
        <Text
          style={{
            fontSize: 14,
            fontWeight: 600,
            color: "white",
          }}
        >
          Switch to Autonomous Drive Mode
        </Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingHorizontal: 16,
    paddingVertical: 28,
    justifyContent: "space-between",
    paddingBottom: 70,
  },
  buttonContainer: {
    flexDirection: "row",
    gap: 16,
    height: 120,
    marginBottom: 16,
  },
  button: {
    flex: 1,
    borderRadius: 8,
    borderColor: "#E5E7EB",
    borderWidth: 1,
    padding: 16,
    justifyContent: "center",
    alignItems: "center",
    gap: 8,
    backgroundColor: "white",
  },
  buttonText: {
    fontSize: 14,
    fontWeight: 600,
  },
  buttonTextSub: {
    fontSize: 14,
  },
  locationContainer: {
    borderRadius: 8,
    padding: 16,
    gap: 8,
    backgroundColor: "white",
    marginBottom: 100,
  },
});
