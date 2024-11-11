n=int(input())
lis=[]
for i in range(n):
    s,f=map(int,input().split())
    lis.append([f,s])    
lis.sort()
count=1
maxl=lis[0][0]
for i in range(1,len(lis)):
    if lis[i][1]>maxl:
        count=count+1
        maxl=lis[i][0]
print(count)