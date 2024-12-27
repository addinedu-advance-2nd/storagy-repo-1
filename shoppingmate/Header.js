import { StatusBar } from "expo-status-bar";
import { Image, StyleSheet, Text, TouchableOpacity, View } from "react-native";
import cart_white from "./assets/cart_white.png";

export default function Header() {
  return (
    <View style={styles.header}>
      <Text style={{ fontSize: 16, fontWeight: "bold" }}>Shoppingmate</Text>
      <View
        style={{
          flexDirection: "row",
          justifyContent: "flex-end",
          gap: 12,
          alignItems: "center",
        }}
      >
        <View style={{ flexDirection: "row", alignItems: "center" }}>
          <Text style={{ fontSize: 14, fontWeight: 600 }}>
            {/*/12 items | $328.50 */}
          </Text>
        </View>
        <TouchableOpacity
          style={{
            backgroundColor: "#1B9AF5",
            paddingHorizontal: 12,
            paddingVertical: 6,
            borderRadius: 8,
            gap: 4,
            flexDirection: "row",
            alignItems: "center",
          }}
        >
          <Image
            style={{ width: 14, height: 14, objectFit: "contain" }}
            source={cart_white}
          />
          <Text style={{ color: "white", fontSize: 14 }}>Cart</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  header: {
    marginTop: 20,
    height: 56,
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
    backgroundColor: "white",
    paddingHorizontal: 20,
    zIndex: 100,
    backgroundColor: "white",
    borderBottomColor: "#E5E7EB",
    borderBottomWidth: 1,
    alignItems: "center",
  },
});
