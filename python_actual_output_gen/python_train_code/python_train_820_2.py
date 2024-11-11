n = int(input())
a = list(map(int,input().split()))
x = list(map(abs,a))
sm = sum(x)
print(sm)
if n&1==0 and len([0 for i in a if i<0])&1==1:
    sm-=2*min(x)
print(sm)