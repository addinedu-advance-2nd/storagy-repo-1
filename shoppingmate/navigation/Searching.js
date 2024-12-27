import {
  Image,
  ScrollView,
  StyleSheet,
  Text,
  TextInput,
  TouchableOpacity,
  View,
} from "react-native";
import sample_image from "../assets/sample_image.png";
import food from "../assets/food.png";
import snack from "../assets/snack.png";
import drink from "../assets/drink.png";
import other from "../assets/other.png";
import food_blue from "../assets/food_blue.png";
import snack_blue from "../assets/snack_blue.png";
import drink_blue from "../assets/drink_blue.png";
import other_blue from "../assets/other_blue.png";
import connected from "../assets/connected.png";
import search_gray from "../assets/search_gray.png";
import map_white from "../assets/map_white.png";
import { useEffect, useState } from "react";
import ROSLIB from "roslib";

let ros, goal_x, goal_y, goal_w;

export default function Searching() {
  const [selectedService, setSelectedService] = useState("");
  const [productLocation, setProductLocation] = useState("상품을 선택해주세요");

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

  const startNavigationPress = () => {
    console.log("startNavigationPress");
    //좌표값
    console.log("goal_x 좌표:" + goal_x);
    // request 준비
    // 그 외 ros 통신 (안내 시작!!)
  };

  const showButton = (image, image_selected, title) => (
    <TouchableOpacity
      style={{
        ...styles.button,
        borderColor: selectedService === title ? "#1B9AF5" : "#E5E7EB",
      }}
      onPress={() => {
        title === selectedService
          ? setSelectedService("")
          : setSelectedService(title);

        if (title == "snack") {
          setProductLocation("칙촉 (x: 0.2, y: 0.2)");
          goal_x = 0.2;
          goal_y = 0.2;
          goal_w = 0.99;
          //console.log(goal_x);
        } else if (title == "food") {
          setProductLocation("식품 (x: 2.7, y: 0.1)");
          goal_x = 2.7;
          goal_y = 0.1;
          goal_w = 0.99;
          //console.log(goal_x);
        } else if (title == "drink") {
          setProductLocation("음료 (x: 2.1, y: 2.2)");
          goal_x = 2.1;
          goal_y = 2.2;
          goal_w = 0.99;
          //console.log(goal_x);
        } else {
          setProductLocation("기타 (x: 1.5, y: 0.7)");
          goal_x = 1.5;
          goal_y = 0.7;
          goal_w = 0.99;
          //console.log(goal_x);
        }
      }}
    >
      <Image
        style={{ width: 24, height: 24, objectFit: "contain" }}
        source={selectedService === title ? image_selected : image}
      />
      <Text
        style={{
          ...styles.buttonText,
          color: selectedService === title ? "#1B9AF5" : "black",
        }}
      >
        {title}
      </Text>
    </TouchableOpacity>
  );

  return (
    <View style={styles.container}>
      <View>
        <View
          style={{
            backgroundColor: "white",
            borderRadius: 8,
            marginBottom: 16,
            flexDirection: "row",
            gap: 14,
            alignItems: "center",
            paddingHorizontal: 12,
            paddingVertical: 8,
          }}
        >
          <Image source={search_gray} style={{ width: 14, height: 14 }} />
          <TextInput
            style={{
              fontSize: 16,
              fontWeight: 400,
              color: "#6B7280",
              width: "90%",
            }}
            placeholder="Search products..."
          />
        </View>
        <View style={styles.buttonContainer}>
          {showButton(food, food_blue, "food")}
          {showButton(snack, snack_blue, "snack")}
        </View>
        <View style={styles.buttonContainer}>
          {showButton(drink, drink_blue, "drink")}
          {showButton(other, other_blue, "other")}
        </View>
      </View>
      <View>
        <View // 설명 시작
          style={{
            width: "100%",
            height: 70,
            borderRadius: 4,
            backgroundColor: "#F9FAFB",
            padding: 12,
            gap: 4,
            marginBottom: 10,
          }}
        >
          <View style={{ flexDirection: "row", gap: 8, alignItems: "center" }}>
            <Text>상품 위치 : {productLocation}</Text>
          </View>
          <Text style={styles.buttonTextSub}> </Text>
        </View>
        {/*설명상자끝 */}
        <TouchableOpacity
          style={{
            paddingHorizontal: 24,
            paddingVertical: 12,
            backgroundColor: selectedService === "" ? "#E5E7EB" : "#1B9AF5",
            flexDirection: "row",
            justifyContent: "center",
            alignItems: "center",
            gap: 8,
            borderRadius: 8,
          }}
          disabled={selectedService === ""}
          onPress={startNavigationPress}
        >
          <Image
            source={map_white}
            style={{ width: 14, height: 14, objectFit: "contain" }}
          />
          <Text
            style={{
              fontSize: 14,
              fontWeight: 600,
              color: "white",
            }}
          >
            Start navigation
          </Text>
        </TouchableOpacity>
      </View>
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
