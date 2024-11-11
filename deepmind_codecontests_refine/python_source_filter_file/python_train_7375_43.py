N=int(input())
a=list(map(int,input().split()))
a.sort()
l=a[N:2*N]
print(sum(l))