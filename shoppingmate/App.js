import { StatusBar } from "expo-status-bar";
import { StyleSheet, Text, View } from "react-native";
import Header from "./Header";
import Main from "./navigation/Main";
import Bottom from "./Bottom";
import Cart from "./navigation/Cart";
import Searching from "./navigation/Searching";
import Map from "./navigation/Map";
import Manual from "./navigation/Manual";
import { NavigationContainer } from "@react-navigation/native";
import { createStackNavigator } from "@react-navigation/stack";

export default function App() {
  const DefaultStack = createStackNavigator();

  function StackNavigator() {
    return (
      <DefaultStack.Navigator
        screenOptions={{
          header: ({ route }) => {
            return null;
          },
        }}
      >
        <DefaultStack.Screen name="Main" component={Main} />
        <DefaultStack.Screen name="Cart" component={Cart} />
        <DefaultStack.Screen name="Searching" component={Searching} />
        <DefaultStack.Screen name="Map" component={Map} />
        <DefaultStack.Screen name="Manual" component={Manual} />
      </DefaultStack.Navigator>
    );
  }

  return (
    <View style={styles.container}>
      <NavigationContainer>
        <StatusBar style="default" />
        <Header />
        <StackNavigator />
        <Bottom />
      </NavigationContainer>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#F9FAFB",
  },
});
