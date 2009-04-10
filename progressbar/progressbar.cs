using System;
using System.Collections;
using System.Threading;

public class Progress {
    public static void fWheel(int digit) {
        ArrayList wheel = new ArrayList();
        wheel.Add("\\");
        wheel.Add("|");
        wheel.Add("/");
        wheel.Add("-");
        Console.Write("\b{0} ", wheel[digit%4]);
    }

    public static void fProgressbar(int len, int digit) {
        int i;

        ArrayList spaces = new ArrayList();
        spaces.Add("[");

        for(i = 0; i < digit; i++) {
            spaces.Add("=");
        }

        for(i = 1; i < len - digit - 2; i++) {
            spaces.Add(" ");
        }

        spaces.Add("]");

        PrintValues(spaces);
        fWheel(digit);
    }

    public static void PrintValues(IEnumerable myList) {
        IEnumerator myEnumerator = myList.GetEnumerator();
        Console.Write("\r");

        while (myEnumerator.MoveNext()) {
            Console.Write(myEnumerator.Current);
        }

        Console.Write("\t ");
    }

    public static void Main() {
        int digit;
        int length = 50;
        for(digit = 1; digit < length - 2; digit++) {
            fProgressbar(length, digit);
            Thread.Sleep(40);
        }
        Console.WriteLine("\b\bDone.");
    }
}
