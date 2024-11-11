from bisect import bisect_left
N = int(input())
A = list(int(input()) for _ in range(N))
S = sorted(S)
A = [bisect_left(S,a) for a in A]
print((sum((i-j)%2 for i,j in enumerate(A))+1)//2)