a = int(input())
for x in range(a):
    b,c,d,e = map(int,input().split())
    f = (abs(d-b)+abs(e-c))
    if d!=b and d!=e:
        f += 1
    print(f)

