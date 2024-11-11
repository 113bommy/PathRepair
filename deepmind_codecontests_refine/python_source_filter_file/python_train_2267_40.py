x,n=map(int,input().split())
p=list(map(int,input().split()))
a=[999]*101
for i in range(101):
    if i not in p:
        a[i]=abs(x-i)
print(a.index(min(a)))