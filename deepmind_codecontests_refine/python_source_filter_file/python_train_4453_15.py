import math

n, H = map(int, input().split())

k = (-1.0 + math.sqrt(1 + 8 * n)) / 2.0

a = int(k)
if a * (a + 1) / 2 < n:
    a += 1

if int(k) <= H:
    print(a)
    
else:
    n += H * (H - 1) // 2
    
    q1 = math.sqrt(n)
    sq1 = int(q1)
    if sq1 * sq1 < n:
        sq1 += 1
    ans1 = sq1 + sq1 - 1
    ans1 -= (H - 1)
    
    q2 = (-1 + math.sqrt(1 + 4 * n)) / 2
    sq2 = int(q2)
    if sq2 * (sq2 + 1) < n:
        sq2 += 1
    ans2 = sq2 + sq2
    ans2 -= (H - 1)
    
    ans = min(ans1, ans2)
    print(ans)