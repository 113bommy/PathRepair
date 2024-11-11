x,y=map(int,input().split())
print(max(x+y-3-((y-x)%3>0),0))
