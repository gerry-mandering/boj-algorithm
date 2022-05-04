import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class boj_1546 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Float> scores = new ArrayList<Float>();
        int amount;
        Float max = 0F, sum = 0F, avg = 0F;

        amount = sc.nextInt();

        for (int i=0; i<amount; i++) {
            scores.add(sc.nextFloat());
        }

        for (int i=0; i<amount; i++) {
            if (scores.get(i) > max) {
                max = scores.get(i);
            }
        }

        for (int i=0; i<amount; i++) {
            scores.set(i, (scores.get(i) / max * 100.0F));
        }

        for (int i=0; i<amount; i++) {
            sum += scores.get(i);
        }

        System.out.println(sum / amount);
    }
}
