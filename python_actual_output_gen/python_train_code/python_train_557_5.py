n=int(input())
A=list(map(int,input().split()))
A.sort()
B=[]
t=A[-1]-A[0]
B.append((A[n-1]-A[0])*(A[-1]-A[n]))
for i in range(n):
    A.append(t*(-A[i]+A[i+n-1]))
print(min(B))