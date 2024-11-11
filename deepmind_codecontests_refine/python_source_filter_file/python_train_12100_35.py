"""

                                            1304A. Two Rabbits
                                            
Being tired of participating in too many Codeforces rounds, Gildong decided to take some rest in a park. 
He sat down on a bench, and soon he found two rabbits hopping around. One of the rabbits was taller than
the other.He noticed that the two rabbits were hopping towards each other. The positions of the two rabbits
can be represented as integer coordinates on a horizontal line. The taller rabbit is currently on position
𝑥, and the shorter rabbit is currently on position 𝑦 (𝑥<𝑦). Every second, each rabbit hops to another position.
The taller rabbit hops to the positive direction by 𝑎, and the shorter rabbit hops to the negative direction by 𝑏.

For example, let's say 𝑥=0, 𝑦=10, 𝑎=2, and 𝑏=3. At the 1-st second, each rabbit will be at position 2 and 7. 
At the 2-nd second, both rabbits will be at position 4.
Gildong is now wondering: Will the two rabbits be at the same position at the same moment?
If so, how long will it take? Let's find a moment in time (in seconds) after which the rabbits will be at the same point.


#Input:

Each test contains one or more test cases. The first line contains the number of test cases 𝑡(1≤𝑡≤1000).
Each test case contains exactly one line. The line consists of four integers 𝑥, 𝑦, 𝑎, 𝑏 (0≤𝑥<𝑦≤109, 1≤𝑎,𝑏≤109) 
  — the current position of the taller rabbit, the current position of the shorter rabbit, the hopping distance
  of the taller rabbit, and the hopping distance of the shorter rabbit, respectively.

#Output:

For each test case, print the single integer: number of seconds the two rabbits will take to be at the same position.
If the two rabbits will never be at the same position simultaneously, print −1.

"""


n = int(input())
for i in range(n):
    x, y, a, b = [int(x) for x in input().split(' ')]
    if (y-x)%(a+b)==0:
        print((y-x)/(a+b))
    else:
        print("-1")