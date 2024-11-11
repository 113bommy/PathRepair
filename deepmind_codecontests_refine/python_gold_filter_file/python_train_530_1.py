def count(x, y, p, q, color):
    if x>p or y>q:
        return 0
    ans = (p-x+1)*(q-y+1)//2 + 1
    if ((x^p)|(y^q)|((x+y)^color)) & 1:
        ans -= 1
    return ans
n = int(input())
for i in range(n):
    ans = 0
    n, m = list(map(int, input().split()))
    x1, y1, x2, y2 = list(map(int, input().split()))
    x3, y3, x4, y4 = list(map(int, input().split()))
    ans = count(1, 1, n, m, 0)
    ans += count(x1, y1, x2, y2, 1)
    ans -= count(x3, y3, x4, y4, 0)
    ans -= count(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4), 1)
    print(ans, m*n-ans)