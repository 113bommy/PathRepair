r,c=map(int,input().split())
lst=[]
t=[]
lt=[[0 for i in range(c)]for i in range(r)]
for i in range(r):
    l=list(input())
    lst.append(l)
    j=0
    while j<c:
        if l[j]=='P':
            tp=i,j
            t.append((i,j))
        if l[j]=='W':
            lt[i][j]=1
        j+=1
def check(lst,i,j):
    if j+1<c and lt[i][j+1]!=0:
        lt[i][j+1]=0
        return 1
    elif j-1>0 and lt[i][j-1]!=0:
        lt[i][j-1]=0
        return 1
    elif i+1<r and lt[i+1][j]!=0:
        lt[i+1][j]=0
        return 1
    elif i-1>0 and lt[i-1][j]!=0:
        lt[i-1][j]=0
        return 1
    return 0
sum=0
for i in t:
    p=check(lst,i[0],i[1])
    if p:
        sum+=1
print(sum)

    
    
