MOD = 10**9+7

import os
import math

def combination(n,k):
    return (math.factorial(n)//math.factorial(k)//math.factorial(n-k))%MOD



def main():

    k = int(input().strip())
    a=[]
    for i in range(k):
        a.append(int(input().strip()))

    dp = [1]
    used=a[0]
    for i in range(1,k):
        used+=a[i]
        dp.append(dp[i - 1] * combination(used - 1, a[i] - 1))

    print(dp[-1])


if __name__ == "__main__":
    main()


"""


3
2
2
1

4
1
2
3
4



"""
