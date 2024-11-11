N, K = map(int, input().split())
A = list(map(int, input().split()))
s = sum(A)
if s % K != 0:
    print("NO")
    exit()
s = s // K
cnt = 0
tmp = 0
rec = []
for i in range(N):
    tmp += A[i]
    cnt += 1
    if tmp == s:
        rec.append(cnt)
        tmp = 0
        cnt = 0
    elif tmp > s:
        print("NO")
        exit()

print("YES")
print(" ".join(map(str, rec)))