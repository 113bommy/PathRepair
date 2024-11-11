n,c= map(int, input().split())
l= list(map(int, input().split()))
m= 100000
temp=[]
for i in range(n-1):
    temp.append(l[i]-l[i+1])

m= max(temp)
if m<=0:
    print(0)
else:
    idx= temp.index(m)
    profit=l[idx]-l[idx+1]-c
    print(profit)
