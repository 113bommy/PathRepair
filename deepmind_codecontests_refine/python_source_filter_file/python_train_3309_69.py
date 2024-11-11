a,b=input().spit()
d={}
d[a]=0
d[b]=0
d[a],d[b]=map(int,input().split())
x=input()
d[x]-=1
print(d[a],d[b])