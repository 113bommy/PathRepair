l,r,a=map(int,input().split())
otv=0
otv+=min(l,r)*2
if l*2==otv:
    r-=otv//2
    l-=otv//2
else:
    r-=otv//2
    l-=otv//2
otv+=max(min(l,a),min(r,a))*2
a-=max(min(l,a),min(r,a))
if a>0:
    otv+=a//2
print(otv)
