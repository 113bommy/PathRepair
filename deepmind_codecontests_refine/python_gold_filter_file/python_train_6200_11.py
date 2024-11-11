n=int(input())

d={}

for i in input().split():
    if int(i) in d:
        d[int(i)]+=1
    else:
        d[int(i)]=1
        
lst=[]       
for i in range(1,31):
    lst.append(2**i)

ans=0   

for i in d:
    for j in lst:
        if j-i in d:
            if j-i!=i:
                ans+=d[j-i]*d[i]
            else:
                ans+=(d[i]-1)*(d[i])
            
print(ans//2)