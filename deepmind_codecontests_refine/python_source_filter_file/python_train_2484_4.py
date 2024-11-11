N = int(input())
A = [int(input()) for i in range(N)]

s = 0
L = [False]*22
for a in A:
    s ^= a
    c = 0
    while a&1==0:
        c += 1
        a >>= 1
    L[c] = True
if s==0:
    print(0)
    exit()
ss = "0" + bin(s)[2:]
ans = 0
for i in range(len(ss)-1):
    if ss[-1-i] != ss[-2-i]:
        if L[i]:
            ans += 1
        else:
            print(-1)
            exit()
print(ans)
