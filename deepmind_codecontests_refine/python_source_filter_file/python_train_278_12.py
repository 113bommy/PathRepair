def lastBacteriaStanding(arr,k,n):
    ans=n
    arr.sort()
    d=1
    for i in range(1,n-1):
        curr=arr[i]
        if(curr==arr[i+1]):
            d+=1
        elif (arr[i]+k>=arr[i+1] and arr[i]<arr[i+1]):
            ans-=d
            d=1
        else:
            d=1
    return ans

n,k=map(int,input().split(' '))
arr=list(map(int,input().split(' ')))
print(lastBacteriaStanding(arr,k,n))