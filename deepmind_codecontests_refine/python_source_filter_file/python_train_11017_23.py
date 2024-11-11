N = int(input())
A = list(map(int, input().split()))
maxi = max((abs(a), i) for i, a in enumerate(A))[1]
if maxi == 0:
    print(0)
    exit()
print(2*(N-1))
for i in range(N):
    if i == maxi: continue
    print(maxi+1, i+1)
if A[maxi] > 0:
    for i in range(N-1):
        print(i+1, i+2)
else:
    for i in range(N-1)[::-1]:
        print(i+2, i+1)