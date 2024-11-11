n,x = map(int,input().split())
r = 0
for _ in range(n):
    s, m = input().split()
    if s == '+': x += int(m)
    else: 
        if int(m)<x: x -= int(m)
        else: r += 1
print(x, r)
