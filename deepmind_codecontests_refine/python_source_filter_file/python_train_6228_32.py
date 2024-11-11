n,m,x,y=map(int,input().split())
a=max(list(map(int,input().split())))
b=min(list(map(int,input().split())))
print("No War" if a<b and x<b else "War")