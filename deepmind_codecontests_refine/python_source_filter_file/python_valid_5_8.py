from collections import Counter, deque
from math import *
mod=1000000007
# from functools import reduce
# from itertools import permutations


def isPrime(n):
    if n<2:
        return False
    if n==2 or n==3:
        return True
    if n%2==0 or n%3==0:
        return False
    for i in range(5,int(sqrt(n)+1),6):
        if n%i==0 or n%(i+2)==0:
            return False
    return True
def solve():
    n = int(input())
    enemy = list(input())
    my = list(input())
    count=0
    for i in range(n):
        if my[i]!='0':
            if enemy[i]=='0':
                count+=1
            else:
                if i=='0':
                    if enemy[i+1]=='1':
                        count+=1
                        enemy[i+1]='0'
                elif i==n-1:
                    if enemy[i-1]=='1':
                        count+=1
                        enemy[i-1]='0'
                else:
                    if enemy[i - 1] == '1':
                        count += 1
                        enemy[i - 1] = '0'
                    elif enemy[i+1]=='1':
                        count+=1
                        enemy[i+1]='0'
    print(count)














t=int(input())
# t = 1
for _ in range(t):
    # print("Case #{}: ".format(_ + 1), end="")
    solve()


