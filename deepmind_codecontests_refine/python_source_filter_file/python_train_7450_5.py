from sys import stdin

A=list(map(int,stdin.readline().split()))
n=A[0]
k=A[1]

while True:
    temp=2**(n)-1
    if k==int(2**(n-1)):
        print(n)
        break
    elif k>int(2**(n-1)):
        k=n-k

    n-=1
    if n==1:
        print(1)
        break