N, K = map(int, input().split())
V = list(map(int, input().split()))

s = 0
for i in range(K): # 左から取り出す回数
    for j in range(K - i): # 右から取り出す回数
        if i + j > N:
            continue
        
        a = V[:i] + V[N-j:]
        r = K - i - j # 戻すことのできる回数

        a.sort()
        for k in range(min(len(a)+1, r+1)):
            s = max(s, sum(a[k:]))

print(s)