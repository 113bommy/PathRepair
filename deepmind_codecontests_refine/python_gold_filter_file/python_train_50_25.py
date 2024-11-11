a,b=map(int,input().split())
s=set()
for i in range(a):
    l=list(map(int,input().split()))
    for j in range(1,len(l)):
        s.add(l[j])
flag=0
for i in range(1,b+1):
    if(i not in s):
        flag=1
        break
if(flag==1):
    print("NO")
else:
    print("YES")
    
    
