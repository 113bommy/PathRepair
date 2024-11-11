from sys import *
for _ in range(int(input())):
    n,m=map(int,input().split())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    A.reverse()
    f=1
    for i in range(n):
        if (A[i]+B[i])>m:
            f=0
    if f==1:
        stdout.write(str("Yes")+"\n")
    else:
        stdout.write(str("No")+"\n")
    stdin.readline()