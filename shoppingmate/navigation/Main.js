import {
  ActivityIndicator,
  Image,
  ScrollView,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
} from "react-native";
import sample_image from "../assets/sample_image.png";
import cart from "../assets/cart.png";
import search from "../assets/search.png";
import map from "../assets/map.png";
import my from "../assets/my.png";
import connected from "../assets/connected.png";
import { useEffect, useState } from "react";
import ROSLIB from "roslib";

let ros;

export default function Main({ navigation }) {
  const [rosConnectStatus, setRosConnectStatus] = useState("Disconnected");
  useEffect(() => {
    ros = new ROSLIB.Ros({
      //ros bridge server와 연동하기 위하여 어디로 접속할지
      url: "ws://192.168.0.101:9090",
    });

    // If there is an error on the backend, an 'error' emit will be emitted.
    ros.on("error", function (error) {
      console.log("Error connecting to websocket server: ", error);
      setRosConnectStatus("Disconnected");
    });

    // Find out exactly when we made a connection.
    ros.on("connection", function () {
      console.log("Connected to websocket server.");
      setRosConnectStatus("Connected");
    });

    ros.on("close", function () {
      console.log("Connection to websocket server closed.");
      setRosConnectStatus("Disconnected");
    });
  }, []); // []안에 있는 값이 바뀔 때 내용물 실행

  const showButton = (image, title, sub, page) => (
    <TouchableOpacity
      style={styles.button}
      onPress={() => page && navigation.navigate(page)}
    >
      <Image
        style={{ width: 24, height: 24, objectFit: "contain" }}
        source={image}
      />
      <Text style={styles.buttonText}>{title}</Text>
      <Text style={styles.buttonTextSub}>{sub}</Text>
    </TouchableOpacity>
  );

  return (
    <ScrollView style={styles.container}>
      <Image
        style={{
          width: "100%",
          height: 200,
          marginBottom: 16,
          borderRadius: 4,
        }}
        source={sample_image}
      />
      <View style={styles.buttonContainer}>
        {showButton(cart, "Call Cart", "쇼핑카트 호출", "Cart")}
        {showButton(search, "Find Products", "상품 검색", "Searching")}
      </View>
      <View style={styles.buttonContainer}>
        {showButton(map, "Mini Map", "지도", "Map")}
        {
          showButton(
            my,
            "Manual Control",
            "비상시 수동조작",
            "Manual"
          ) /*showButton(my, "My Info", "Member: Gold", "Manual")*/
        }
      </View>
      <View style={styles.locationContainer}>
        <View
          style={{
            flexDirection: "row",
            justifyContent: "space-between",
            alignItems: "center",
          }}
        >
          <Text style={styles.buttonText}>Connection Status</Text>
          <View
            style={{
              flexDirection: "row",
              alignItems: "center",
              gap: 4,
            }}
          >
            {rosConnectStatus === "Connected" && (
              <Image source={connected} style={{ width: 17.5, height: 12 }} />
            )}
            <Text
              style={{
                fontSize: 14,
                color: rosConnectStatus === "Connected" ? "#16A34A" : "#CA8A04",
              }}
            >
              {rosConnectStatus}
            </Text>
          </View>
        </View>
        {/*<View
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
            <Text>Aisle 5 - Electronics Section</Text>
          </View>
          <Text style={styles.buttonTextSub}>
            Cart is moving to your location...
          </Text>
        </View>*/}
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
