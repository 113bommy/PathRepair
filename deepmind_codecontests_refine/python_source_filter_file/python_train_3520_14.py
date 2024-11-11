N = int(input())
As = list(map(int, input().split()))
ma = sum(As)
o = dict()
INF = 10**19
from itertools import accumulate
aa = [0] + list(accumulate(As))

for i in range(N):
    for j in range(N-i):
        span = i*N+j
        # 長さi+1, 開始位置jの合成コスト+構成要素の和
        if i == 0:
            o[span] = As[j]
            continue
        C = INF
#        print(i,j,o)
        for k in range(i):
            # 長さk+1とi+1-(k+1)=i-kに分割
#            print(i,j,k*N+j, (i-k-1)*N+j+k)
            C = min(C, o[k*N+j]+o[(i-k-1)*N+j+k])
#        o[span] = C + sum(As[j:j+i+1])
        o[span] = C + aa[j+i+1] - aa[j]

print(o[span]-ma)
