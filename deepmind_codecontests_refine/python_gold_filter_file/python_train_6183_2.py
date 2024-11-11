inp=input().split(' ')
l=int(inp[0])
d=int(inp[1])
v=int(inp[2])
g=int(inp[3])
r=int(inp[4])
n=0
while((d/v)>(n*(g+r))):
    n+=1
n-=1
t=d/v-n*(g+r)

if(t<g):
    print(l/v)
else:
    print(d/v+r-t+g+(l-d)/v)