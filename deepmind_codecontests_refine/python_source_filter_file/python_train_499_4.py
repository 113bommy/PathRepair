a,b,c,x,y=map(int,input().split())
ans=[]
ans.append(a*x+b*y)
ans.append(c*2*x+a*max(0,y-x))
ans.append(c*2*y+b*max(0,x-y))
print(min(ans))