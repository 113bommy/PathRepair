n=int(input())
cnt=0
while 2**cnt-1<=n:
  cnt+=1
cnt-=1
graph=[]
for i in range(cnt):
  graph.append((1+i,2+i,2**i))
  graph.append((1+i,2+i,0))
existmax=2**cnt-1
for i in range(1,cnt+1)[::-1]:
    if 2**(i-1)-1+existmax+1<=n-1:
        graph.append((i,cnt+1,existmax+1))
        existmax=existmax+1+2**(i-1)-1
L=len(graph)
print(cnt+1,L)
for i in graph:
  print(*i)
