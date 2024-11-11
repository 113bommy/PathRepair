__author__ = 'Bryan'

n,m,dx,dy = map(int, input().split())
x,y,j = 0,0,0
ans,ind = [0]*n,[0]*n

for i in range(1,n):
    x,y = (x+dx)%n,(y+dy)%n
    ind[x]=y

for i in range(m):
    x,y = map(int, input().split())
    ans[(y-ind[x]+n)%n]+=1

for i in range(n):
    if ans[i]>ans[j]:
        j = i

print(0,j)
