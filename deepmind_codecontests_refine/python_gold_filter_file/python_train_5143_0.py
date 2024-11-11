a,b,c,d = map(int, input().split())
if d - c == c - b and c - b == b - a:
    print(d + d - c)
elif b*d == c*c and a*c == b*b and (d*d)%c == 0:
    print(d*d//c)
else:
    print(42)
