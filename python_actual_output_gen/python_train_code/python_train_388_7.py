n=int(input())
a=list(map(int,input().split()))

b=a*1;b.sort()
low=a.index(b[0])+1
high=a.index(b[-1])+1

if low>high:
    low,high=high,low

print(max(n-low,high))