n = int(input())
d = [int(_) for _ in input().split()]
a, b = map(int, input().split())
ans = 0
for i in range(1,b):
    ans+=d[i-1]
print (ans)    