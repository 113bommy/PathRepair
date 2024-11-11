from sys import stdin
input = stdin.buffer.readline
    
n=int(input())
arr=[int(x) for x in input().split()]

arr.sort()
s=set(arr)
print(s)
flag=False
for ele in arr:
    for i in range(31):
        if ((ele-2**i) in s) and ((ele+2**i) in s):
            ans=[ele,ele-2**i,ele+2**i]
            flag=True
            break
    if flag:
        break
if flag:
    print(3) 
    print(*ans)    
    exit()
for ele in arr:
    for i in range(31):
        if (ele+2**i) in s:
            ans=[ele,ele+2**i]
            flag=True
            break
    if flag:
        break
if flag:
    print(2)
    print(*ans)
else:
    print(1)
    print(arr[0])