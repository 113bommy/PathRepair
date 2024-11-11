n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    items=list(map(int,input().split()))
    t=sum(items)*5+len(items)*15
    a.append(t)
print(min(a))