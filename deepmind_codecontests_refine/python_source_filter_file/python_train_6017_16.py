import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, M, V, P = mapint()
As = list(mapint())
As.sort(reverse=True)

threshold = As[P-1]
l, r = P, N
while l+1<r:
    half = (l+r)//2
    a = As[half]+M
    if a<threshold:
        r = half
    else:
        rest_sum = 0
        for i in range(P-1, N):
            if As[i]>=a:
                continue
            if i==half:
                continue
            rest_sum += min(M, a-As[i])
        if M*V > rest_sum+P*M:
            r = half
        else:
            l = half
print(l+1)