A=list(map(int,input().split()))
n,x=A[0],A[1]
lst=[]
for i in range(n):
    a=sorted(list(map(int,input().split())))
    lst.append(a)
arr=set(range(lst[0][0],lst[0][1]+1))    
for i in range(0,len(lst)):
    arr=arr.intersection(set(range(lst[i][0],lst[i][1])))
if len(arr)==0:
    print('-1')
else:
    if min(arr)<=x<=max(arr):
        print('0')
    elif abs(max(arr)-x)>abs(min(arr)-x):
        print(abs(min(arr)-x))
    else:
        print(abs(max(arr)-x))
