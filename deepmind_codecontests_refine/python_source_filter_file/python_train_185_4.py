a,b=map(int ,input().split())
x=int(pow(b,1/a))
x+=1
while x>=1:
    if b%(x**a)==0:
        print(x)
        exit()
    x-=1

