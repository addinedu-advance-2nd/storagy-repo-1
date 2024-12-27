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
import qr_sample from "../assets/qr_sample.png";
import connected from "../assets/connected.png";
import { useEffect, useState } from "react";
import ROSLIB from "roslib";

let ros;
let CallCartClient, CallCart_feedback_listener;
let current_pose_x, current_pose_y;

export default function Cart() {
  const [distanceRemaining, setDistanceRemaining] = useState();
  const [precentage, setPercentage] = useState(20);
  const [isQRExist, setIsQRExist] = useState(false);

  const [distanceText, setDistanceText] = useState("Searching");
  useEffect(() => {
    if (distanceRemaining <= 0.2) setDistanceText("Connected");
  }, [distanceRemaining]);

  const generateQR = () => {
    // setIsQRExist(true);
    setIsQRExist(!isQRExist);
  };

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

  const callCartPress = () => {
    console.log("callCartPress");
    setIsQRExist(!isQRExist);
    CallCartClient = new ROSLIB.Service({
      ros: ros,
      name: "order", //"/i6robotics_navigation_server", //'/turtle1/teleport_absolute', //서비스 명
      serviceType: "i6robotics_control_msgs/srv/Order", //"i6robotics_control_msgs/srv/NavOrderSrv", //메시지타입
    });
    var request = new ROSLIB.ServiceRequest({
      //리퀘스트 메시지 내용
      order: "nav_to_pose",
      goal_pose: {
        position: { x: 0.817, y: -1.89, z: 0.0 },
        orientation: { x: 0.0, y: 0.0, z: 0.99, w: 0.1 },
      },
    });

    CallCartClient.callService(request, function (result) {
      //clearTimeout(timeoutId); // 응답이 오면 타임아웃을 취소
      console.log(
        "Result for service call on " +
          CallCartClient.name +
          ": " +
          result.result
      );
    });

    CallCart_feedback_listener = new ROSLIB.Topic({
      ros: ros,
      name: "/i6robotics_navigation_feedback", //토픽이름
      messageType: "i6robotics_control_msgs/msg/NavOrderFeedback",
    });

    var lastExecutionTime = Date.now();
    CallCart_feedback_listener.subscribe(function (message) {
      //consol.log (JSON.stringify(message));
      var now = Date.now();

      // 1초마다만 실행되도록 제한
      if (now - lastExecutionTime >= 100) {
        lastExecutionTime = now; // 마지막 실행 시간을 업데이트r
        setDistanceRemaining(message.distance_remaining.toFixed(2));
        current_pose_x = message.current_pose.pose.position.x;
        current_pose_y = message.current_pose.pose.position.y;
        console.log("distance_remaining: " + distanceRemaining);
        // 메시지 처리
        console.log(
          "Remaining Distance : " +
            CallCart_feedback_listener.name +
            ": " +
            message.distance_remaining +
            " m"
        );
        console.log(
          "Currnet location : " +
            CallCart_feedback_listener.name +
            ": [" +
            message.current_pose.pose.position.x +
            "," +
            message.current_pose.pose.position.y +
            "]"
        );
      }
      //CallCart_feedback_listener.unsubscribe(); //subscribe 해제
    });
  };

  return (
    <ScrollView style={styles.container}>
      <View
        style={{
          backgroundColor: "#F3F4F6",
          height: 360,
          borderRadius: 8,
          marginBottom: 16,
          justifyContent: "center",
          alignItems: "center",
        }}
      >
        {isQRExist ? (
          <Pressable onPress={callCartPress}>
            <Image source={qr_sample} style={{ width: 300, height: 300 }} />
          </Pressable>
        ) : (
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
            onPress={callCartPress}
          >
            <Image source={qr_white} style={{ width: 12.25, height: 12.25 }} />
            <Text style={{ fontSize: 14, color: "white" }}>
              Generate QR Code
            </Text>
          </TouchableOpacity>
        )}
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
          marginBottom: 16,
        }}
        onPress={callCartPress}
      >
        <Image
          source={cart_white}
          style={{ width: 14, height: 14, objectFit: "contain" }}
        />
        <Text style={{ fontSize: 14, fontWeight: 600, color: "white" }}>
          Call Cart
        </Text>
      </TouchableOpacity>
      <View style={styles.locationContainer}>
        <View
          style={{
            flexDirection: "row",
            justifyContent: "space-between",
            alignItems: "center",
          }}
        >
          <Text style={styles.buttonText}>Cart Location</Text>
          <View
            style={{
              flexDirection: "row",
              alignItems: "center",
              gap: 4,
            }}
          >
            {distanceText === "Searching" && (
              <ActivityIndicator size="small" color="#CA8A04" />
            )}
            <Text
              style={{
                fontSize: 14,
                color: distanceText === "Searching" ? "#CA8A04" : "#16A34A",
              }}
            >
              {distanceText}
            </Text>
          </View>
        </View>
        <View
          style={{
            width: "100%",
            height: 64,
            borderRadius: 4,
            backgroundColor: "#F9FAFB",
            padding: 12,
            gap: 4,
          }}
        >
          <View style={{ flexDirection: "row", gap: 8, alignItems: "center" }}>
            <Image
              source={cart}
              style={{ width: 12, height: 12, objectFit: "contain" }}
            />
            <Text>Waiting for cart matching...</Text>
          </View>
          <Text style={styles.buttonTextSub}>
            {/* Looking for available carts nearby... */}
            {distanceRemaining
              ? " Remaining Distance:" + distanceRemaining + "m"
              : "Looking for available carts nearby..."}
          </Text>
        </View>
        {/* <View
          style={{
            flex: 1,
            flexDirection: "row",
            alignItems: "center",
            gap: 8,
            justifyContent: "space-between",
          }}
        >
          <View
            style={{
              flex: 0.9,
              height: 8,
              borderRadius: 100,
              backgroundColor: "#E5E7EB",
              position: "relative",
            }}
          >
            <View
              style={{
                width: `${precentage}%`,
                height: 8,
                borderRadius: 100,
                backgroundColor: "#16A34A",
                position: "absolute",
              }}
            ></View>
          </View>
          <Text style={{ ...styles.buttonTextSub, flex: 0.1 }}>
            {precentage}%
          </Text>
        </View> */}
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingHorizontal: 16,
    paddingVertical: 28,
    gap: 16,
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
    fontSize: 12,
    color: "#6B7280",
  },
  locationContainer: {
    borderRadius: 8,
    padding: 16,
    gap: 8,
    backgroundColor: "white",
    marginBottom: 100,
  },
});
