p=[0]*4
p[0],p[1],p[2],p[3],a,b=input().split(' ')
p[0],p[1],p[2],p[3],a,b=int(p[0]),int(p[1]),int(p[2]),int(p[3]),int(a),int(b)
ans=max(min(p)-a,0)
if min(p)>b:
    ans-=min(p)-b-1
print(ans)
