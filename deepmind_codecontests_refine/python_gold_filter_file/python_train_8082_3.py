n = map(int, input().split())
a = sorted(list(map(int, input().split())))

t2 = 0
t1 = 0
for it in a:
    if (it % 2 == 0):
        t2 = t2 + 1
    else:
        t1 = t1 + 1
        
ans = min(t1, t2)

t1 -= ans

ans += int(t1) // 3

print(ans)