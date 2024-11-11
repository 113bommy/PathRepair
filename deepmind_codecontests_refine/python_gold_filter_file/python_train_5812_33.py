n,t = map(int,input().split())
m = 1001
for i in range(n):
    c,d = map(int,input().split())
    if d <= t:
        m = min(m,c)
print('TLE' if m == 1001 else m)
