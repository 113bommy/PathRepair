a,d=map(int,input().split())
ans=[]
for i in range(a):
    z=list(map(int,input().split()))
    ans.append(z)
ans.sort(key=lambda x: (x[0],x[1]))
l=0
r=0
maxa=[]
mi=0
i=0

while(l<=r and r<len(ans)):
    if(ans[r][0]-ans[l][0]<d):
        mi+=ans[i][1]
        r+=1
        i+=1
    else:
        maxa.append(mi)
        l+=1
        mi=maxa[-1]-ans[l-1][1]
maxa.append(mi)     

print(max(maxa))
