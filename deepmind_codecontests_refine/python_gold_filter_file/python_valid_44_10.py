for i in range(int(input())):
    c,d=map(int,input().split())
    if abs(c-d)%2==1:
        print(-1)
        continue
    if c==0 and d==0:
        print(0)
        continue
    if c==d:
        print(1)
        continue
    print(2)