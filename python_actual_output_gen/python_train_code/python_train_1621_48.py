n=int(input())
d=list(map(int,input().split()))
d.sort()
e=d[n//2]
f=d[n//2+1]
print(f-e)