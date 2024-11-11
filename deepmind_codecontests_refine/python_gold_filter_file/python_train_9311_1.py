#very good solution i like this
def seq(arr):
    l=[1]*len(arr)
    r=[1]*len(arr)
    for i in range(1,len(arr)):
        if arr[i]>arr[i-1]:
            l[i]=l[i-1]+1
    for i in range(len(arr)-2,-1,-1):
        if arr[i]<arr[i+1]:
            r[i]=r[i+1]+1
    m=max(l)
    if m<len(arr):
        m+=1
    for i in range(1,len(arr)-1):
        if arr[i-1]+1<arr[i+1]:
            m=max(m,l[i-1]+r[i+1]+1) 
    return m
a=input()
lst=list(map(int,input().strip().split()))
print(seq(lst))