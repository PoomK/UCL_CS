package exercise1;

public class Example1_1
{
    public int sumOfDigits(int n)
    {
        int sum = 0;
        n = Math.abs(n);
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public void inputAndProcess()
    {
        int n = 0;
        Input in = new Input();
        while (true)
        {
            System.out.print("Type an integer: ");
            if (in.hasNextInt())
            {
                n = in.nextInt();
                break;
            }
            in.nextLine();
            System.out.println("You did not type an integer, try again.");
        }
        System.out.print("The sum of the digits of: " + n);
        System.out.println(" is: " + sumOfDigits(n));
    }

    // The main method should do no more than create the object
    // and call a method to do the work.
    public static void main(String[] args)
    {
        new Example1_1().inputAndProcess();
    }
}
