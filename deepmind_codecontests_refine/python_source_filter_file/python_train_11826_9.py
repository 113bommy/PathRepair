n=int(input())
A=list(map(int,input().split(" ")))
A.sort()
mindiff=10**9+1
for i in range(1,n):
    mindiff=min(mindiff,A[i]-A[i-1])
ct=0
for i in range(1,n):
    if A[i]-A[i-1]==mindiff:
        ct+=1
print(mindiff,ct)
