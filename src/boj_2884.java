import java.util.Scanner;

public class boj_2884 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int hour, minute;
        hour = sc.nextInt();
        minute = sc.nextInt();

        if (minute < 45) {
            minute = minute + 15;
            if (hour == 0) {
                hour = 23;
            } else {
                hour -= 1;
            }
        } else {
            minute = minute - 45;
        }

        System.out.println(hour + " " + minute);

    }
}
