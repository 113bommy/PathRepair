n,k = list(map(int,input().split()))
s = "".join([str(i) for i in range(k+1)])
res = 0
for _ in range(n):
    x = list(input())
    x = set(x)
    x = list(x)
    x.sort()
    x = "".join(x)
    if x==s:
        res+=1
print(res)
    
