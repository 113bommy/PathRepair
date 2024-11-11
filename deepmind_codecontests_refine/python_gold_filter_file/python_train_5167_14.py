s=input()
l=len(s)
ans=10000000000
arr=[[0,-1] for i in range(26)]
#print(s)
for i in range(l):
    k=ord(s[i])-ord('a')
    arr[k][0]=max(i-arr[k][1],arr[k][0])
    arr[k][1]=i
#    print(k,arr[k],arr)
#print(arr)      
for i in range(26):
    arr[i][1]=-1    
#print(arr)
for i in range(l-1,-1,-1):
    k=ord(s[i])-ord('a')
    if arr[k][1]==-1:
        arr[k][0]=max(l-i,arr[k][0])
        arr[k][1]=i
#    print(arr,k)    
#print(arr)    
for i in range(26):
    if arr[i][1]!=-1:
        ans=min(ans,arr[i][0])
print(ans)        

