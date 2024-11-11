n=int(input())
*a,=map(int,input().split())
a.sort()
print(sum(a[n:2*n]))