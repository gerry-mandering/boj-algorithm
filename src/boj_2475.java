import java.util.Scanner;

public class boj_2475 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] num = new int[5];
        int sum = 0;

        for (int i=0; i<5; i++) {
            num[i] = sc.nextInt();
        }

        for (int i : num) {
            sum += Math.pow(i, 2);
        }

        System.out.println(sum % 10);
    }
}
