N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
cp = 0
cm = 0
for i in range(N):
    if A[i]>B[i]:
        cm += A[i]-B[i]
    elif B[i]>A[i]:
        cp += B[i]-A[i]
if cp//2>=cm:
    print("Yes")
else:
    print("No")