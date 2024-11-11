for _ in range(int(input())):
    a,b,x,y = map(int, input().split())
    li = [
        a*y, (a-x-1)*b, a*(b-y-1), (a-x-1)*b
    ]
    print(max(li))