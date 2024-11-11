q = int(input())
for i in range(q):
    a,b,c = map(int,input().split())
    if (a+b+c)%2 == 0:
        print((a+b+c)//2)
    else:
        print((a+b+c-1)//2)