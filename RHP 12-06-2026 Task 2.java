import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int q = sc.nextInt();

        int MAX = 200000;

        int[] diff = new int[MAX + 2];
        int[] admissible = new int[MAX + 2];
        int[] prefix = new int[MAX + 2];

        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();

            diff[l]++;
            diff[r + 1]--;
        }

        int count = 0;

        for (int i = 1; i <= MAX; i++) {
            count += diff[i];

            if (count >= k) {
                admissible[i] = 1;
            }

            prefix[i] = prefix[i - 1] + admissible[i];
        }

        while (q-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println(prefix[b] - prefix[a - 1]);
        }

        sc.close();
    }
}