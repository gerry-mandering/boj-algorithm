import java.util.Scanner;

import static java.lang.Math.*;

public class boj_1002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count;
        int x1, y1, r1, x2, y2, r2;
        double distance;
        count = sc.nextInt();
        int[] result = new int[count];
        for (int i=0; i<count; i++) {
            x1 = sc.nextInt();
            y1 = sc.nextInt();
            r1 = sc.nextInt();
            x2 = sc.nextInt();
            y2 = sc.nextInt();
            r2 = sc.nextInt();

            distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

            if (distance == 0 && r1 == r2) {
                result[i] = -1;
            } else if (distance == 0 || r1 + r2 < distance || abs(r1 - r2) > distance) {
                result[i] = 0;
            } else if (r1 + r2 == distance || abs(r1 - r2) == distance) {
                result[i] = 1;
            } else {
                result[i] = 2;
            }
        }

        for (int j=0; j<count; j++) {
            System.out.println(result[j]);
        }
    }
}
