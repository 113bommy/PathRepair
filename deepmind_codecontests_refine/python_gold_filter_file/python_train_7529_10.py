#-------------Program-------------
#----KuzlyaevNikita-Codeforces----
#

n=int(input())
arr=[]
for i in range(n):
    f=list(map(int,input().split()))
    arr.append(f)
k=-3*(arr[n//2][n//2])
for i in range(n):k+=arr[i][n-1-i]
for i in range(n):k+=arr[i][i]
k+=sum(arr[n//2])
for i in range(n):k+=arr[i][n//2]

print(k)