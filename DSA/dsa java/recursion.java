
public class recursion {
    public static void main(String[] args) {
        // skip("", "baaccdd");
        System.out.println(skipapp("baacappbca"));

    }

    static void skip(String p, String up) {

        if (up.isEmpty()) {
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        if (ch == 'a') {
            skip(p, up.substring(1));
        } else {
            skip(p + ch, up.substring(1));
        }
    }

    // if you have to return the string
    static String skip(String up) {
        if (up.isEmpty()) {
            return "";
        }

        char ch = up.charAt(0);

        if (ch == 'a') {
            return skip(up.substring(1));
        } else {
            return ch + skip(up.substring(1));
        }
    }

    // if you have to skip entire string then
    static String skipapple(String up) {
        if (up.isEmpty()) {
            return "";
        }

        char ch = up.charAt(0);

        if (up.startsWith("apple")) {
            return skipapple(up.substring(5));
        } else {
            return ch + skipapple(up.substring(1));
        }
    }

    // skip particular if it does not starting with "...."
    static String skipapp(String up) {
        if (up.isEmpty()) {
            return "";
        }

        char ch = up.charAt(0);

        if (up.startsWith("app") && !up.startsWith("apple")) {
            return skipapp(up.substring(3));
        } else {
            return ch + skipapp(up.substring(1));
        }
    }

}