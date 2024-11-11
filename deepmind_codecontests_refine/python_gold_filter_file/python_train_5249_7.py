n,m,k=input().split(" ")
n=int(n)
m=int(m)
k=int(k)
h=0
l=list(map(int,input().split(" ")))
for i in range(n):
    if(l[i]==1):
        if(m==0):
            h=h+1
        else:
            m=m-1
    else:
        if(m==0 and k==0):
            h=h+(n-i)
            break
        elif(k>0):
            k=k-1
        else:
            m=m-1
print(h)