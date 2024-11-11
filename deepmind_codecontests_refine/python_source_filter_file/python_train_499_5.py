a,b,c,x,y=map(int,input().split())
ans=[]
ans.append(a*x+b*y)
ans.append(c*x+b*max(0,y-x))
ans.append(c*y+a*max(0,x-y))
print(min(ans))