n, *p = map(int, open(0).read().split())
t = 0
for i in range(n):
    t += 1 if p[i] != sorted(p)[i] 
print("YES" if t == 0 or t == 2 else "NO")