n=int(input())
arr=[]
rra=[]

for i in range (n):
    z=list(map(int,input().split()))
    arr.append(z[0])
    rra.append(z[1])
count=0

for i in range(n) :
    temp=arr[i]
    indexx=i
    arr.remove(temp)
    if rra[i] in arr :
        arr.insert(indexx,temp)
    else :
        count+=1
        arr.insert(indexx,temp)
print(count)
