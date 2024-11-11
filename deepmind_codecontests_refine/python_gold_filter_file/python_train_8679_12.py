t=int(input())
a=list(map(int,input().split()))
i=1
flag=0
a.sort()
for j in range(0,len(a)):
    if a[j]!=i:
        flag=1
        break
    i+=1
if flag==0:
    print(t+1)
else:
    print(i)
