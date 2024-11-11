x,y=map(int,input().split())

ans=10**10

if x<=y: ans=min(ans,y-x)
elif -x<=y: ans=min(ans,y+x+1)
elif x<=-y: ans=min(ans,-y-x+1)
elif -x<=-y: ans=min(ans,-y+x+2)

print(ans)
