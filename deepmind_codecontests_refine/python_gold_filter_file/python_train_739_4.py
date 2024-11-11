n=int(input())
arr=[]
for i in range(n):
    arr.append(int(input()))
x=sum(arr)
for i in range(2**n):
    s=0
    for j in range(n):
        if i&(1<<j):
            s+=arr[j]
    if (x-2*s)%360==0 or x%360==0:
        print('YES')
        break
else:
    print('NO')