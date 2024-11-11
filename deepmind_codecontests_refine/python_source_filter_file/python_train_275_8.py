import copy 
n,k=list(map(int,input().split()))
li=list(map(int,input().split()))
stack=copy.deepcopy(li)
stack.sort(reverse=True)
for i in range(len(li)):
    li[i]=li[i]+k
li.sort()
ans=n
i=0
print(li)
while i<n and len(stack)>0:
    po=len(stack)-1
    while  len(stack)>0 and li[i]-k==stack[po]:
        stack.pop()
        po=len(stack)-1
        
    
    if  len(stack)>0 and stack[po]<=li[i]:
        i=i+1
        ans=ans-1
    elif len(stack)>0 and stack[po]>li[i]:
        i=i+1
print(ans)
            
        
    

    
       
