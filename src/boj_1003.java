import java.util.Scanner;

class Memo
{
	int	fibo_result;
	int	zero_call_count;
	int	one_call_count;

	Memo()
	{
	}

	Memo(int fibo_result, int zero_call_count, int one_call_count)
	{
		this.fibo_result = fibo_result;
		this.zero_call_count = zero_call_count;
		this.one_call_count = one_call_count;
	}
}

public class Main
{
	public static void main(String[] args)
	{
		Scanner	sc = new Scanner(System.in);
		Memo[]	memo = new Memo[41];
		Memo	result = new Memo();
		int		repeat = sc.nextInt();
		int		n;

		init_memo(memo);
		for (int i = 0; i < repeat; i++)
		{
			n = sc.nextInt();
			result = fibo_memo(n, memo);

			System.out.println(result.zero_call_count + " " + result.one_call_count);
		}
	}

	public static void init_memo(Memo[] memo)
	{
		for (int i = 0; i < 41; i++)
		{
			memo[i] = new Memo(-1, 0, 0);
		}
	}

	public static Memo fibo_memo(int n, Memo[] memo)
	{
		if (memo[n].fibo_result != -1)
		{
			return (memo[n]);
		}
		else
		{
			if (n == 0)
			{
				memo[0].fibo_result = 0;
				memo[0].zero_call_count = 1;

				return (memo[0]);
			}
			else if (n == 1)
			{
				memo[1].fibo_result = 1;
				memo[1].one_call_count = 1;

				return (memo[1]);
			}
			else
			{
				Memo	temp = new Memo();
				Memo	temp2 = new Memo();

				temp = fibo_memo(n - 1, memo);
				temp2 = fibo_memo(n - 2, memo);

				memo[n].fibo_result = temp.fibo_result + temp2.fibo_result;
				memo[n].zero_call_count = temp.zero_call_count + temp2.zero_call_count;
				memo[n].one_call_count = temp.one_call_count + temp2.one_call_count;

				//메모리 해제
				temp = null;
				temp2 = null;

				return (memo[n]);
			}
		}
	}
}
