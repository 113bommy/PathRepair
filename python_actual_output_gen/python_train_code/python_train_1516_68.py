a, b, c, d, e, f = map(int, input().split())

op1 = abs(a-b)*d
op2 = (abs(a-c)*e)+(abs(a-b)*e)+(f*3)

if op1 > op2:
    print("YES")
else:
    print("NO")