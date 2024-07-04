import java.lang.reflect.Array;
import java.util.ArrayList;

public class maze {
    public static void main(String[] args) {
        // System.out.println("number of ways:" + count(3, 3));
        // path("", 3, 3);
        // System.out.println(pathret("", 3, 3));
        // System.out.println(pathdia gonal("", 3, 3));

        boolean[][] arr = {
                { true, true, true },
                { true, true, true },
                { true, true, true }
        };
        // pathobstacle(" ", arr, 0, 0);
        pathall("", arr, 0, 0);
    }

    static int count(int r, int c) {
        if (r == 1 || c == 1) {
            return 1;
        }

        int left = count(r - 1, c);
        int right = count(r, c - 1);
        return left + right;
    }

    static void path(String p, int r, int c) {

        if (r == 1 && c == 1) {
            System.out.println(p);
            return;
        }

        if (r > 1) {
            path(p + 'D', r - 1, c);
        }
        if (c > 1) {
            path(p + 'R', r, c - 1);
        }
    }

    // if we have to print the answer in the arraylist
    static ArrayList<String> pathret(String p, int r, int c) {

        if (r == 1 && c == 1) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> list = new ArrayList<>();

        if (r > 1) {
            list.addAll(pathret(p + 'D', r - 1, c));
        }
        if (c > 1) {
            list.addAll(pathret(p + 'R', r, c - 1));
        }
        return list;
    }

    // if we want to go by diagonal also then.....
    static ArrayList<String> pathdiagonal(String p, int r, int c) {

        if (r == 1 && c == 1) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> list = new ArrayList<>();

        if (r > 1) {
            list.addAll(pathdiagonal(p + 'V', r - 1, c));
        }
        if (r > 1 && c > 1) {
            list.addAll(pathdiagonal(p + 'D', r - 1, c - 1));
        }
        if (c > 1) {
            list.addAll(pathdiagonal(p + 'H', r, c - 1));
        }
        return list;
    }

    // if we have obstacle in the path then....
    static void pathobstacle(String p, boolean[][] arr, int r, int c) {

        if (r == arr.length - 1 && c == arr[0].length - 1) {
            System.out.println(p);
            return;
        }

        if (!arr[r][c]) {
            return;
        }

        if (r < arr.length - 1) {
            pathobstacle(p + 'D', arr, r + 1, c);
        }
        if (c < arr[0].length - 1) {
            pathobstacle(p + 'R', arr, r, c + 1);
        }
    }

    // if there is all directions like L , R , U , D then.... (Backtracking )
    static void pathall(String p, boolean[][] arr, int r, int c) {

        if (r == arr.length - 1 && c == arr[0].length - 1) {
            System.out.println(p);
            return;
        }

        if (!arr[r][c]) {
            return;
        }

        // i am considering this block in my path
        arr[r][c] = false;

        if (r < arr.length - 1) {
            pathall(p + 'D', arr, r + 1, c);
        }

        if (c < arr[0].length - 1) {
            pathall(p + 'R', arr, r, c + 1);
        }

        if (r > 0) {
            pathall(p + 'U', arr, r - 1, c);
        }

        if (c > 0) {
            pathall(p + 'L', arr, r, c - 1);
        }
        // this line is where the function will be over
        // so before the function gets removed , also removes the changes maked
        arr[r][c] = true;
    }
}