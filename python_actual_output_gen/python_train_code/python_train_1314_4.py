import math
def solve(n) :
    if (n < 2) : return 0
    else :
        for i in range(2, int(math.sqrt(n))) :
            if (n % i == 0) : return 0
    return 1
s = input().split()
n = int(s[0])
if (solve(n) == 1) : print(1)
elif (n % 2 == 0) : print(2)
elif (solve(n - 2) == 1) : print(2)
else : print(3)