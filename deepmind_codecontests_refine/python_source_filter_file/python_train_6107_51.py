str=input()
n=0
m=0
ans='NO'
arr=[]
for char in str:
    arr.append(int(char))
arr.append(0)
for i in range(0,len(arr)-1):
    if(arr[i]==0):
        n=n+1
        m=0
        if(n>=7):
            ans='YES'
        
      
    if(arr[i]==1):
        m=m+1
        n=0
        if(m>=7):
            ans='YES'
       
       
print(arr,ans,m,n)