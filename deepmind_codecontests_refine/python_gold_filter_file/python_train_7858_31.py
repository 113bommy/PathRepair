n=int(input())
A=[int(x)for x in input().split()]
B=[]
num=1
if n==1:
    print(n)
else:
    for i in range(1,n):
        if A[i]>=A[i-1]:
            num+=1
        else:
            num=1
        B.append(num)
    print(max(B))
