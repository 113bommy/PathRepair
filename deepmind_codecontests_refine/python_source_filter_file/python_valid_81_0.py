from itertools import accumulate
from sys import stdin, stdout
input = stdin.readline
def print(x): return stdout.write(str(x) + "\n")

for _ in range(int(input())):
    n, q = map(int, input().split())
    s = input()
    nums = []
    for i in range(n):
        if (s[i] == '+' and i%2==0) or (s[i]== '-' and i%2==1):
            nums.append(1)
        else:
            nums.append(0)

    a = list(accumulate(nums)) # total number of '+' at or to the left of i.

    for _ in range(q):
        li, ri = map(int, input().split())
        if (ri-li) % 2 == 0:
            print(1)
        
        elif li == 1 and a[ri-1] == (ri-1)//2:
            print(0)
        
        elif li != 1 and a[ri-1] - a[li-2] == (ri-li+1)//2:
            print(0)

        else:
            print(2)


