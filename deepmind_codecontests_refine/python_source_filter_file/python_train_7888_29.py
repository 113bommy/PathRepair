n=int(input())

list=[]
for i in range(n):
 x,l=map(int,input().split())
 list.append([x-l+1,x+l-1])
list=sorted(list,key=lambda x:x[1])

cnt=0
min=-10**18
for r,l in list:
 if min<r:
  cnt+=1
  min=l
print(cnt)