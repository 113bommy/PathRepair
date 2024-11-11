n=int(input())
cN=0
p=0
inp=list(map(int, input().split()))
x=[]
for i in range (0,n):
    x.insert(i,inp[i])
    if(x[i]<0):
        if(p>0):
            p=p-1
        else:
            cN=cN+1
    else:
        p=x[i]
print(cN)




