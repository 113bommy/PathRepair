n=int(input())
arr1=[]
arr2=[]
count=0
for i in range(n):
    b=list(map(int,input().split()))
    
    arr1.append(b[0])
    arr2.append(b[1])
for i in range(len(arr1)):
    for j in range(len(arr2)):
        if i!=j and arr1[i]==arr1[j]:
            count+=1
print(count)
