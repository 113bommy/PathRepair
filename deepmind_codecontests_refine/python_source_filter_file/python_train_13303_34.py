t1,t2 = list(map(int, input().split()))
a1,a2 = list(map(int, input().split()))
b1,b2 = list(map(int, input().split()))
x=(a1-b1)*t1 + (a2-b2)*t2
if x == 0:
    print("infinity")
if x*(a1-b1) > 0:
    print(0)
else:
    s,t = divmod(abs((a1-b1)*t1), abs(x))
    if t:
        print(s*2+1)
    else:
        print(s*2)
