t=int(input())
lst=[]
res=[]
for i in range(0,t):
   lst=[int(i) for i in input().split()]
   ele=9*lst[0]+lst[1]
   res.append(ele)

for i in range(0,t):
   print(res[i])