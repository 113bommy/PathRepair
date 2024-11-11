for i in range(int(input())):
    x,y=[int(num) for num in input().split()]
    if x==y:
        print(x,y)
        continue
    if y>=x*2:
        print(x,2*x)
    else:
        print(-1,-1)
