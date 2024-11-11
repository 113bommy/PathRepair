'''Author- Akshit Monga'''
import math
t=int(input())
for _ in range(t):
    n=int(input())
    arr=[int(x) for x in input().split()]
    if sum(arr)%n!=0:
        print(-1)
        continue
    p=sum(arr)//n
    ans=[]
    for i in range(1,n):
        if arr[i]%(i+1)==0:
            x=arr[i]//(i+1)
            arr[0] += arr[i]
            arr[i]=0
            ans.append((i+1,i,x))
        else:
            delta=(math.ceil(arr[i]/(i+1))*(i+1))-(arr[i])
            ans.append((1, i + 1, delta))
            arr[0]-=delta
            arr[i]+=delta
            assert arr[i]%(i+1)==0
            x = arr[i] // (i + 1)
            arr[0] += arr[i]
            arr[i] = 0
            ans.append((i + 1, i, x))
        # print(arr[0])
    # print(arr)
    for i in range(1,n):
        ans.append((1,i+1,p))
        arr[0]-=p
        arr[i]+=p
    print(len(ans))
    print(arr)
    for i in ans:
        print(i[0],i[1],i[2])