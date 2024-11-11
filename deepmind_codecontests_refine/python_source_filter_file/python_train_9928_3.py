n=int(input())
curr=list([i for i in range(1,100)]) 
curr=set(curr)
def isvalid(x):
    if x<1 or x>10**9:
        return 0 
    if len(set(str(x)))<=2:
        return 1 
cnt=0 
while cnt<=4*(10**4 ):
    curr1=set()
    for i in curr:
        for j in range(10):
            if isvalid(i*10+j):
                curr1.add(i*10+j)
               # print('hi')
                cnt+=1 
    #print(curr1)
    curr|=curr1 
curr=sorted(list(curr))
#print(curr)
ans=0 
for i in curr:
    if i>=1 and i<=n:
        ans+=1 
    elif i>n:
        break 
print(ans)