for __ in range(int(input())):
    b,c=map(int,input().split())
    x=[int(i) for i in input().split()]
    # print(sum(x))
    if sum(x)>=c:print(c)
    else:print(sum(x))
