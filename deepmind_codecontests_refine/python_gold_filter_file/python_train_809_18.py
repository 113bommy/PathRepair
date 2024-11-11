N = int(input())
A = list(map(int, input().split()))

xor = A[0]
for i in range(N-1):
    xor = xor ^ A[i+1]
    
if xor == 0:
    print("Yes")
else:
    print("No")