import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int[]	score_arr;
		int		people_total = sc.nextInt();
		int		except_min = sc.nextInt();
		int		except_max = sc.nextInt();

		score_arr = new int[people_total];

		for (int i = 0; i < people_total; i++)
		{
			score_arr[i] = sc.nextInt();
		}
		
		System.out.println(get_final_score(score_arr, people_total, except_min, except_max));
	}

	public static double get_final_score(int[] score_arr, int size, int except_min, int except_max)
	{
		double	final_score, sum = 0;

		bubble_sort(score_arr, size);

		for (int i = except_min; i < size - except_max; i++)
		{
			sum += score_arr[i];
		}

		final_score = sum / (size - (except_min + except_max));

		return (final_score);
	}

	public static void bubble_sort(int[] score_arr, int size)
	{
		int temp;

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (score_arr[j] > score_arr[j + 1])
				{
					temp = score_arr[j];
					score_arr[j] = score_arr[j + 1];
					score_arr[j + 1] = temp; 
				}
			}
		}
	}
}
