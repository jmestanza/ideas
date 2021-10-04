import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
import java.math.BigInteger;

class Result {
    static BigInteger[] factorial = new BigInteger[100+1];
    static public void compute_factorials(){
        for (int i = 0; i <= 100; i++) {
            if(i == 0 || i == 1){
                factorial[i] = new BigInteger("1");
            }else{
                BigInteger bigI = new BigInteger(String.valueOf(i));
                factorial[i] = factorial[i-1].multiply(bigI);
            }
        }
    }
    /*
     * Complete the 'extraLongFactorials' function below.
     *
     * The function accepts INTEGER n as parameter.
     */

public static void extraLongFactorials(int n) {
        // Write your code here
        System.out.println(factorial[n]);
    }

}

public class Solution {
public static void main(String[] args) throws IOException {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

            int n = Integer.parseInt(bufferedReader.readLine().trim());

            Result.compute_factorials();
            Result.extraLongFactorials(n);

            bufferedReader.close();
    }
}
