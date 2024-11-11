t1,t2 = map(int, input().split())
a1,a2 = map(int, input().split())
b1,b2 = map(int, input().split())
x,y=(a1-b1)*t1 + (a2-b2)*t2, (a1-b1)*t1
if x == 0:
    print("infinity")
elif x*y > 0:
    print(0)
else:
    s,t = divmod(abs(y), abs(x))
    print(s*2+1 if t else 0)
