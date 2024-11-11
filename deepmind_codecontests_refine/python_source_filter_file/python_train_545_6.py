from math import ceil
def cnter(arr):
    if arr==[]:
        return False
    ans=list(map(lambda s:s%len(arr),arr))
    if ans.count(0)==len(arr) or len(arr)==1:
        return True

    return False
def multiples(arr):
    if len(arr)<=3:
        print(1,1)
        print(-arr[0])
        if len(arr)>=2:
            print(2, 2)
            print(-arr[1])
        else:
            print(1,1)
            print(0)
        if len(arr)>=3:
            print(3, 3)
            print(-arr[2])
        else:
            print(1,1)
            print(0)
        return ""
    print(1,len(arr))
    for i in range(0,len(arr)):
        if i==len(arr):
            print(0)
        else:
            print(-arr[i]*(len(arr)),end=" ")
    print("")
    print(1,len(arr)-1)
    for i in range(0,len(arr)-1):
        print(arr[i]*(len(arr)-1),end=" ")
    print("")
    print(len(arr),len(arr))
    print(-arr[-1])
    return ""

a=input()
lst=list(map(int,input().strip().split()))
print(multiples(lst))