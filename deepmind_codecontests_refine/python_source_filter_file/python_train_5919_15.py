#AGC 013 A - Sorted Arrays
#増加⇔減少に転じる際、Ai+1 - Aiは必ず符号反転することを利用
N = int(input())
A = list(map(int,input().split()))

count = 0
sign = 0
for i in range(N):
    if sign == 0:
        sign = A[i+1]-A[i]
    elif sign*(A[i+1]-A[i]) < 0:
        count += 1
        sign = 0
print(count)