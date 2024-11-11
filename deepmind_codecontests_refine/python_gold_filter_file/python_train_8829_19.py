# 中央値が最適値(数直線で考える)
N = int(input())
A = [int(i) for i in input().split()]
for i in range(len(A)):
    A[i] -= i+1
A.sort()
b = A[N // 2]
print(sum([abs(a-b) for a in A]))
