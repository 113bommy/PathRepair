N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
x = 0
y = 0
for i in range(N):
    if A[i]>B[i]:
        x += A[i]-B[i]
    else:
        y += B[i]-A[i]
if y>=2*x:
    print("Yes")
else:
    print("No")