N=int(input())
B = [int(i) for i in input().split()]
A = [B[0]]+[min(B[i-1],B[i]) for i in range(N-1)]+[B[-1]]
print(sum(A))
