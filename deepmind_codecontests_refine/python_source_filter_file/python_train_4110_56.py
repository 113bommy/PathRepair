a,b,c,d = map(int, input().split())
e = max(3*a//10, a-a*b//250)
f = max(3*c//10, c-c*d//250)
if e > f:
    print("Vasya")
elif e < f:
    print("Misha")
else:
    print("Tie")