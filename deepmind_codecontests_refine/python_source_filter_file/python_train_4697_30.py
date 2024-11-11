s1 = input().split()
a = int(s1[0])
b = int(s1[1])
c = int(s1[2])
ans = 0
if a == b == c:
    print(0)
if a < b + c and b < a + c and c < a + b:
    print(0)
else:
    p = max(a, b, c)
    y = min(a, b, c)
    t = (a + b + c) - p - y
    ans = p - (t+y)+1
    print(ans)