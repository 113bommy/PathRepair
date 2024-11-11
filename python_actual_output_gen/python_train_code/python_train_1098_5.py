n=int(input())
arr=[]
for i in range(n):
    arr.append(input())
s=set(arr)
p=i
M=0
lis=[]
for i in s:
    lis.append([arr.count(i),i])
lis=sorted(lis)
print(lis[0][1])

    