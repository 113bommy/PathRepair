n = int(input())
A = list(map(int, input().split()))
B = [ A[i]-i-1 for i in range(n) ]
idx = n//2
print( sum( [ abs(b-B[idx]) for b in B ] ) )