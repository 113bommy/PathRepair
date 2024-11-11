n,d,h = [int(i) for i in input().split()]
if d > 2*h or (h == 1 and d == 1 and n != 2):
    print(-1)
elif d > h:
    for i in range(2,h+2):
        print(i-1,i)
    print(1,h+2)
    for i in range(h+3,d+2):
        print(i-1,i)
    for i in range(d+2,n+1):
        print(h,i)
elif d == h:
    for i in range(2,h+2):
        print(i-1,i)
    for i in range(d+2,n+1):
        print(h,i)
