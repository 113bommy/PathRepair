n,m,k=map(int,input().split())
count=0
ans=[]
for i in range(n-1):
    ans.append("L")
    count+=1
for i in range(m-1):
    ans.append("D")
    count+=1
mode=1
for i in range(m):
    if mode==1:
        for i2 in range(n-1):
            ans.append("R")
            count += 1
        mode=0
    else:
        for i2 in range(n-1):
            ans.append("L")
            count+=1
        mode=1
    ans.append("U")
    count+=1
print(count)
for i in ans:
    print(i,end="")