import random


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


for _ in range(int(input())):
    # n = int(input())
    # a = list(map(int, input().split()))
    n,m = map(int, input().split())
    fl=0
    for i in range(n):
        f,s=map(int, input().split())
        t,fo=map(int, input().split())
        if s==t:
            fl=1
    if m%2==1 :
        print('NO')
    else:
        if  m==2 and fl==0:
            print('NO')
        else:
            print('YES')

    #print(n,m)


