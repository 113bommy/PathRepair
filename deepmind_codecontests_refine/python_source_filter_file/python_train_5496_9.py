M = int(input())

cnt = 0
cnt_c = 0
L = []
for _ in range(M):
    d, c = map(int, input().split())
    cnt += c*d
    cnt_c += c   

ans = cnt//10 + cnt_c - 1
print(ans)