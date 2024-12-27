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
import { useEffect, useState } from "react";
import ROSLIB from "roslib";

let ros;

export default function Map() {
  const [cartX, setCartX] = useState(500); //50, 80
  const [cartY, setCartY] = useState(500);

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
  }, []);

  const CurrentLocationPress = () => {
    var Odometry_listener = new ROSLIB.Topic({
      ros: ros,
      name: "/odom", //토픽이름
      messageType: "nav_msgs/msg/Odometry",
    });

    Odometry_listener.subscribe(function (message) {
      //console.log(JSON.stringify(message));
      if (message.pose.pose.position.x < 0) {
        message.pose.pose.position.x *= -1;
      }
      if (message.pose.pose.position.y < 0) {
        message.pose.pose.position.y *= -1;
      }
      setCartX(((message.pose.pose.position.x * 100) / 3.2 + 50).toFixed(0));
      setCartY(((message.pose.pose.position.y * 100) / 3.3 + 20).toFixed(0));
      console.log(cartX);
      console.log(cartY);

      Odometry_listener.unsubscribe(); //subscribe 해제
    });
  };

  return (
    <ScrollView style={styles.container}>
      <Text
        style={{
          fontSize: 20,
          fontWeight: 700,
          marginBottom: 16,
        }}
      >
        Mini Map
      </Text>
      <View
        style={{
          backgroundColor: "white",
          height: 360,
          borderRadius: 8,
          marginBottom: 16,
          justifyContent: "center",
          alignItems: "center",
          position: "relative",
        }}
      >
        <Image source={map_sample} style={{ width: "85%", height: 300 }} />
        <View
          style={{
            position: "absolute",
            top: cartY,
            left: cartX,
            width: 12,
            height: 12,
            borderRadius: 100,
            backgroundColor: "#EF4444",
          }}
        />
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
        onPress={CurrentLocationPress}
      >
        <Image
          source={location_white}
          style={{ width: 14, height: 14, objectFit: "contain" }}
        />
        <Text style={{ fontSize: 14, fontWeight: 600, color: "white" }}>
          Estimate Current Location
        </Text>
      </TouchableOpacity>
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
        <Image source={map} style={{ width: 10.5, height: 14 }} />
        <Text style={{ fontSize: 14, fontWeight: 500 }}>
          현재 위치 정보: [ x : {cartX} , y : {cartY} ]
        </Text>
      </View>
      <View style={styles.locationContainer}>
        <View
          style={{
            flexDirection: "row",
            justifyContent: "space-between",
            alignItems: "center",
          }}
        >
          <Text style={styles.buttonText}>Nearby Sections</Text>
        </View>
        <View
          style={{
            flexDirection: "row",
            justifyContent: "space-between",
          }}
        >
          <Text style={styles.buttonTextSub}>Aisle 4 - Home Appliances</Text>
          <Text style={styles.buttonTextSub}>←</Text>
        </View>
        <View
          style={{
            flexDirection: "row",
            justifyContent: "space-between",
          }}
        >
          <Text style={styles.buttonTextSub}>Aisle 6 - Smartphones</Text>
          <Text style={styles.buttonTextSub}>→</Text>
        </View>
        <View
          style={{
            flexDirection: "row",
            justifyContent: "space-between",
          }}
        >
          <Text style={styles.buttonTextSub}>Checkout Counter</Text>
          <Text style={styles.buttonTextSub}>↑</Text>
        </View>
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
