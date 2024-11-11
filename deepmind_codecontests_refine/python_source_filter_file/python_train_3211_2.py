n,z,w=map(int,input().split())
A=[int(x) for x in input().split()]
print(max(abs(A[n-2]-A[n-1]),abs(A[n-1],w))) if n!=1 else print(abs(a[0]-w))