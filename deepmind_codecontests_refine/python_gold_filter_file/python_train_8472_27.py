a,b=map(int,input().split())
if(a%2==0):
    half = a//2
else:
    half = a//2 + 1

if(b<=half):
    print((2*b)-1)
else:
    print(2*(b-half))
