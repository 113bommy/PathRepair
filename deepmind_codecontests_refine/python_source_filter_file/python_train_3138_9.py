from itertools import combinations,permutations
from collections import defaultdict
import math
import sys
import os


def solution(n,a):


    sm=sum(a)
    ans=sm
    a.sort()

    for i in range(1,n):
        for x in range(a[i]-1,1,-1):
            if a[i]%x==0:
                ans=min(ans, sm-a[i]-a[0]+a[i]/x+a[0]*x)

    return ans


def main():

    n = int(input().strip())
    arr=list(map(int,input().strip().split()))


    print(solution(n,arr))




if __name__ == '__main__':
    main()


"""

5
1 2 3 4 5


4
4 2 4 4


5
2 4 2 3 7



"""