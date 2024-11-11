a,b=[*map(int,input().split())]
c,d=[*map(int,input().split())]
e=[]
count=0
for i in range(0,100):
    e.append(b+a*i)
for j in range(0,100):
    ans=d+c*j
    if ans in e:
        count+=1
        ans1=ans
        break
if count==1:
    print(ans1)
else:
    print(-1)