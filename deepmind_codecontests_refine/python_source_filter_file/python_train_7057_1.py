S = list(input())
N = len(S)
K = int(input())
if len(set(S)) == 1:
    print((N*K)//2)
    exit()

cnt = 0
tmpS = S[:]
for i in range(N-1):
    if tmpS[i] == tmpS[i+1]:
        cnt += 1
        tmpS[i+1] = '!'

if S[N-1] == S[0]:
    a = 1
    while a <= N-1 and S[a-1] == S[a]:
        a += 1
    b = 1
    while b <= N-1 and S[N-b] == S[N-b-1]:
        b += 1
    print(cnt*K+(a//2+b//2-(a+b)//2)*(K-1))
else:
    print(cnt*K)