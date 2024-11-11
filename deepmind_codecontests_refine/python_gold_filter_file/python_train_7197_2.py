a = b = 0
ans = 1

n = int(input())
for i in range(0, n):
    x, y = map(int, input().split())
    ans += max(0, (min(x,y) - max(a,b)) + (a != b))
    a, b = x, y 
print(ans)