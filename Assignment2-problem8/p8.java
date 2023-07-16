import java.util.*;

class Job
{
    char id;
    int deadline, profit;

    // Constructors
    public Job() {}

    public Job(char id, int deadline, int profit)
    {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }

    void print(ArrayList<Job> arr, int t)
    {
        // Length of array
        int n = arr.size();

        Collections.sort(arr,
                (a, b) -> b.profit - a.profit);
        boolean result[] = new boolean[t];


        char job[] = new char[t];

        // Iterate through all given jobs
        for (int i = 0; i < n; i++)
        {

            for (int j
                 = Math.min(t - 1, arr.get(i).deadline - 1);
                 j >= 0; j--) {

                // Free slot found
                if (result[j] == false)
                {
                    result[j] = true;
                    job[j] = arr.get(i).id;
                    break;
                }
            }
        }


        for (char jb : job)
        {
            System.out.print(jb + " ");
        }
        System.out.println();
    }

    // Driver code
    public static void main(String args[])
    {
        ArrayList<Job> arr = new ArrayList<Job>();

        arr.add(new Job('a', 4, 20));
        arr.add(new Job('b', 1, 10));
        arr.add(new Job('c', 1, 40));
        arr.add(new Job('d', 1, 30));
        //arr.add(new Job('e', 3, 15));

        // Function call
        System.out.println("Following is maximum profit sequence of jobs");

        Job job = new Job();

        // Calling function
        job.print(arr, 3);
    }
}
  