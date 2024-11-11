



la,ra,ta=map(int,input().split())
lb,rb,tb=map(int,input().split())
g=0

def gcd(a,b):
    global g
    if b==0:
        g=a
        return a
    else:
        gcd(b,a%b)

gcd(ta,tb)
difff=((lb-la)%g + g)% g
da=ra-la+1
db=rb-lb+1
ans=max(min(max(da-difff,0),db),min(db-(g-difff),0),da)

print(ans-1)





