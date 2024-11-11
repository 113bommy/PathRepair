t=int(input())
for i in range(t):
    x=input()
    arr=[]
    count=0
   
    for j in range(len(x)):
        if x[j]=="1" :
            count+=1
        else:
            arr.append(count)
            count=0
    arr.append(count)
    arr.sort(reverse=True)
    print(arr)
    ans=0
    for j in range(len(arr)):
        if j%2==0 :
            ans+=arr[j]
   
    print(ans)
   