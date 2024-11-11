for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    arr.sort()
    s=sum(arr)
    sumarr=[]
    a=0
    for i in arr:
      a+=i 
      sumarr.append(a)
    ans=-10**9
    for i in range(n-1):
        ans=max(ans,(sumarr[i]/(i+1))+((s-sumarr[i])/(n-i-1)))
    print(ans)