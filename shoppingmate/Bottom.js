import { Image, StyleSheet, Text, TouchableOpacity, View } from "react-native";
import home from "./assets/home.png";
import categories from "./assets/categories.png";
import deals from "./assets/deals.png";
import account from "./assets/account.png";

export default function Bottom() {
  const showMenu = (image, title) => (
    <TouchableOpacity style={{ gap: 4, alignItems: "center" }}>
      <Image
        style={{ width: 12, height: 12, objectFit: "contain" }}
        source={image}
      />
      <Text style={{ fontSize: 12 }}>{title}</Text>
    </TouchableOpacity>
  );
  return (
    <View style={styles.bottom}>
      {showMenu(home, "Home")}
      {showMenu(categories, "Categories")}
      {showMenu(deals, "Deals")}
      {showMenu(account, "Account")}
    </View>
  );
}

const styles = StyleSheet.create({
  bottom: {
    position: "absolute",
    bottom: 0,
    left: 0,
    width: "100%",
    height: 50,
    backgroundColor: "white",
    borderTopColor: "#E5E7EB",
    borderTopWidth: 1,
    flexDirection: "row",
    justifyContent: "space-around",
    alignItems: "center",
  },
});
