n=int(input())
lst=[]
upper=0
lower=0
c=0
for i in range(n):
    a=list(map(int,input().split()))
    upper+=a[0]
    lower+=a[1]
    lst.append(a)

for i in range(len(lst)):
    
    upper=lower=0
    for j in lst:
        upper+=j[0]
        lower+=j[1]
    if upper%2==0 and lower%2==0:
        break
    else:
        lst[i][1],lst[i][0]=lst[i][0],lst[i][1]
        c+=1
if upper%2==0 and lower%2==0:
    if c>=1:
        print(1)
    else:
      print(0)
else:
    print(-1)
   