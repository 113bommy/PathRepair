t1,t2 = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())
if t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2:
    print("infinity")
    exit()
if a1 < b1:
    tnp = a1
    a1 = b1
    b1 = tnp
    tnp = a2
    a2 = b2
    b2 = tnp
if (a1-b1) * t1 + (a2-b2) * t2 > 0:
    print(0)
    exit()
num = -(a1-b1) * t1 - (a2-b2) * t2
ans = 1

ans += ((a1-b1)*t1 // num)*2
if (a1-b1) % num == 0:
    ans -= 1
print(ans)