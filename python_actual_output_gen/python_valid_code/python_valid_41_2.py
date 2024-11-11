n = int(input())

for i in range(n):
    l = list(map(int, line.split()))
    l.sort()
    if l[0]**2 + l[1]**2 == l[3]**2: print("YES")
    else: print("NO")