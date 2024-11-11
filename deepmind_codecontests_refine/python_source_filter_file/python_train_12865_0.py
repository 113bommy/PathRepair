n,m=map(int,input().split())
Table=[]
for r in range(n):
    row=list(map(int,input().split()))
    Table.append(row)
# print(*Table)
k=int(input())
Tasklist=[]
for task in range(k):
    l,r=map(int,input().split())
    Tasklist.append([l,r])
locate=[0]*(n)
# print(locate)



for c in range(m):
    start=0
    for r in range(0,n-1):
        if(Table[r][c]<=Table[r+1][c]):
            pass
        else:
            for index in range(start,r):
                if(locate[index]<r):
                    locate[index]=r
            start=r+1
    for index in range(start,n):
        if(locate[index]<(n-1)):
            locate[index]=n-1
                
                    



# print(locate)

for task in range(k):
    Task=Tasklist[task]
    l=Task[0]
    r=Task[1]  
    if(locate[l-1]>=(r-1)):
        print("Yes")
    else:
        print("No")
        
        