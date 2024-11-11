n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
    
res=l[0]+1
for i in range(1,n):
    if(l[i]<l[i-1]):
        res+=l[i-1]-l[i]+2
    elif(l[i]==l[i-1]):
        res+=2
    else:
        res+=(l[i]-l[i-1]+2)
print(res)