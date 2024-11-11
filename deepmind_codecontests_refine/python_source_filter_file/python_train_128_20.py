for _ in range(int(input())):
    a,b=map(int,input().split())
    arr1=list(map(int,input().split()))
    arr2=list(map(int,input().split()))
    count=0
    for i in range(len(arr1)):
        for j in range(len(arr2)):
            if arr1[i]==arr2[j]:
                count+=1
                a=arr1[i]
                break
    
    if count>=1:
        print("YES")
        print(count,a)
    else:
        print("NO")