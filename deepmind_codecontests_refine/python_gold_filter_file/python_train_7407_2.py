# cook your dish here
n=int(input())
arr=[0]*(n+1)
arr[0]=-1
y=[0]
for i in range(1,n+1):
    y.append(int(input()))
    
for i in range(1,n+1):
    if y[i]==-1:
        arr[i]=1
    elif y[i]>i:
        x=y[i]
        count=1
        while x>i:
            x=y[x]
            count+=1
        
        arr[i]=arr[x]+count
            
    else:
        arr[i]=arr[y[i]]+1

#print(arr)
print(max(arr))
    

