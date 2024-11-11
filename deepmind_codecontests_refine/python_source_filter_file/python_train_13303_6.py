t1,t2 = map(int, input().split())
a1,a2 = map(int, input().split())
b1,b2 = map(int, input().split())

d1=(a1-b1)*t1
d2=(a2-b2)*t2


if abs(d1) == abs(d2):
    print("infinity")
    exit()

if abs(d1) > abs(d2) or d1*d2>0
    print(0)
    exit()

dif = abs(d2) - abs(d1)

ans=2*(abs(d1)//dif)
if abs(d1)%dif != 0:
    ans+=1
print(ans)