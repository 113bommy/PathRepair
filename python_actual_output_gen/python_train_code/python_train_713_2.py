a,b,c=map(int,input().split())
if c<b:print(1+c,1)
else:
    c-=a;r=c//(b-1);k=c-r*(b-1)
    if r%2==0:print(a-r,2+k)
    else:print(a-r,b-k)