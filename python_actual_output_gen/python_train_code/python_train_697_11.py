n,k=map(int, input().split())
l=list(map(int, input().split()))
cnt=1
d=dict()
stack=[]
j=0
ls=0
for i in range(n):
    if l[i] not in d:
        
        if ls==k:
            d[stack[j]]=None
            j+=1
            stack.append(l[i])
            d[l[i]]=1
        else:
            stack.append(l[i])
            ls+=1
            d[l[i]]=1
stack=stack[::-1]
print(min(len(set(l)),k))
print(*stack[0:min(len(set(l)),k)])