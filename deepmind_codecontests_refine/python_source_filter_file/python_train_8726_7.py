h,w,d=map(int,input().split())
dict={}

for i in range(1,h+1):
  lst=list(map(int,input().split()))
  for j in range(w):
    dict.setdefault(lst[j],(i,j+1))

cost=[0]*(h*w-d)

for i in range(d,h*w-d):
  cost[i]=cost[i-d]+abs(dict[i-d+1][0]-dict[i+1][0])+abs(dict[i-d+1][1]-dict[i+1][1])


ans=0

q=int(input())
for i in range(q):
    ans=0
    l,r=map(int,input().split())
    print(cost[r-1]-cost[l-1])