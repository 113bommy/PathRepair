n=int(input())
ar=sorted(list(map(int,input().split())))
k=n//2
t=sum(ar[:k])
t1=sum(ar[k:])
print(t**2+t1**2)