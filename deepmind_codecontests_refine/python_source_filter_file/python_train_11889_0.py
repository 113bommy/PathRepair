def minSwaps(arr): 
    n = len(arr) 
    vis = {k:False for k in range(n)} 
    par = {k:0 for k in range(n)} 
    for i in range(n): 
        if vis[arr[i]]: 
            continue
        cycle_size = 0
        j = i 
        curr=[]
        while not vis[arr[j]]: 
            curr.append(arr[j])
            vis[arr[j]] = True
            j = arr[j]
            cycle_size += 1
        if cycle_size > 0: 
            print(curr)
            for f in curr:
                par[f]=cycle_size
    # return answer 
    return par 
  
q=int(input())
for _ in range(q):
    n=int(input())
    a=list(map(int,input().split()))
    for i in range(len(a)):
        a[i]-=1
    d=minSwaps(a)
    #print(d)
    for i in a:
        print(d[i],end=" ")
    print()