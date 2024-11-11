N = int(input())
A = list(map(int,input().split()))
B = sorted(A)
print(B[N/2]-B[N/2-1])