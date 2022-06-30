import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int[]	arr;
		int		size, temp;

		size = sc.nextInt();
		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		for (int j = 0; j < size - 1; j++)
		{
			for (int k = 0; k < size - j - 1; k++)
			{
				if (arr[k] > arr[k + 1])
				{
					temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}

		for (int u = 0; u < size; u++)
		{
			System.out.println(arr[u]);
		}
	}
}
