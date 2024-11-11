import bisect
n,t=map(int,input().split())
a=input()
ta=sorted(a)
max_ele=ta[-1]
min_ele=ta[0]
if(t<=n):
    arr=list(a[:t])
    for i in range(1,t+1):
        if(arr[-i]!=max_ele):
            arr[-i]=ta[bisect.bisect_right(ta,arr[-i])]
            break
    if(i>1):
        for j in range(t-i+1,t):
            arr[j]=min_ele
    print("".join(arr))
else:
    arr=list(a)
    #print(arr)
    arr+=[min_ele]*(t-n)
    print("".join(arr))




