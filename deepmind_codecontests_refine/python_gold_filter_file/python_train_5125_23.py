from sys import stdin,stdout,setrecursionlimit
for _ in range(int(stdin.readline())):
    # n=int(stdin.readline())
    n,k=list(map(int,stdin.readline().split()))
    a=list(map(int,stdin.readline().split()))
    for i in range(1,n):
        while k-i>=0 and a[i]>0:
            a[0]+=1
            a[i]-=1
            k-=i
    print(a[0])