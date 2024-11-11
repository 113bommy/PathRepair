n,a,b= map(int,input().split()) 
x = list(map(int,input().split()))
ans = []
for i in range(n):
    d = (x[i]-a) // b
    ans.append(x[i] - d*b - a)
print(*ans)