S=list(str(input()))
temp=[]
ans=0
last=S[0]
for i in range(1,len(S)):
    temp.append(S[i])
    if temp!=last:
        last=temp
        temp=[]
        ans+=1
    
print(ans)
