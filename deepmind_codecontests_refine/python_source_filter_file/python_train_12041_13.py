def wr(n):
    if n<=5 :
        print(-1)
        return
    print(1,2)
    print(2,3)
    print(3,4)
    print(5,2)
    print(6,2)
    x=7
    while x<=n:
        print(1,x)
        x+=1
def cr(n):
    x=2
    while(x<=n):
        print(1,x)
        x+=1
n=int(input())

wr(n)
cr(n)
