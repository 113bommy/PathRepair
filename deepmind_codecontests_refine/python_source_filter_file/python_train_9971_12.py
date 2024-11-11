from statistics import median

N = int(input())
A = [0] * N
B = [0] * N
max=0
min =0
for c in range(N):
    A[c], B[c] = map(int, input().split())

med_A = median(A)
med_B = median(B)

if N%2==0:
    print((med_B-med_A)*2+1)
else:
    print(med_B-med_A+1)