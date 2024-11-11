from math import gcd


def gcd_list(A):
    num=A[0]
    for i in A:
        num=gcd(num,i)
    return num


n,k=map(int,input().split())
A=list(map(int,input().split()))
print("POSSIBLE" if k%gcd_list(A)==0 and k<=max(A) else "IMPOSSIBLE")