T1, T2 = map(int, input().split())
A1, A2 = map(int, input().split())
B1, B2 = map(int, input().split())

d1 = T1*(A1-B1)
d2 = T2*(A2-B2)
if d1>d2:
    d1 *= -1
    d2 *= -1

if (d1>0 and d1+d2>0) or (d1<0 and d1+d2<0):
    print(0)
elif d1+d2==0:
    print("infinity")
else:
    v = (abs(d1)//(d1+d2))
    ans = v*2
    pos = d1+v*(d1+d2)
    if pos<0 and pos+d2>=0:
        ans += 1
    print(pos)