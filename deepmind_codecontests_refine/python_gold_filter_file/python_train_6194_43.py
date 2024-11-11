from array import*
n=int(input())
arr=array('i',list(map(int,input().split())))
arr=sorted(arr)
val=arr[0]
if val==1:
    print(-1)
else:
    print(1)