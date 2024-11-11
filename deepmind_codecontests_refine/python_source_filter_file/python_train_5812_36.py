n,t = map(int,input().split())
m = 101
for i in range(n):
    c,d = map(int,input().split())
    if d <= t:
        m = min(m,c)
print('TLE' if m == 101 else m)
