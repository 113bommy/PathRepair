data = input().split()

N, K, L     =  int(data[0]), int(data[1]), int(data[2])
R, Sall, Sk =  int(data[3]), int(data[4]), int(data[5])

answer = [0] * N

total_s_k = Sall - Sk

for i in range(K):
    answer[i] = Sk // K
    if Sk%K != 0 :
        answer[i] += 1
        Sk -= 1
if K != N:
    for i in range(K, N):
        answer[i] = total_s_k // (N - K)
        if total_s_k%(N-K) != 0:
            answer[i] += 1
            total_s_k -= 1

print(" ".join(map(str, answer)))
