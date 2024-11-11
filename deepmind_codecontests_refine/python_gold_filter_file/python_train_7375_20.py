N=int(input())
a=list(map(int,input().split()))
a.sort()
b=a[N::2]
print(sum(b))