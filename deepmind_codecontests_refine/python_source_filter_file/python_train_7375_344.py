n = int(input())
A = sorted(list(map(int, input().split())), reverse=True)

print(sum(A[n:2*n]))