n,x,y = list(map(int, input().split()))
a = list(map (int, input().split()))

if x > y :
    print(len(a))
else:
    b = {i for i in a if i <= x}
    if len(b)%2 == 0:
        print(len(b)//2)
    else:
        print(len(b)//2 + 1)


