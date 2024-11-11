import bisect
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
ans = 10**9+7
for i in range(2**N):
    card = [[],[]]
    num = []
    iii = i
    for j in range(N):
        if i&1:
            num.append(B[j])
            card[(j+1)%2].append(j)
        else:
            num.append(A[j])
            card[(j)%2].append(j)
        i >>= 1
    if len(card[1]) != N//2:
        continue
    card[0].sort(key=lambda x:[num[x],x])
    card[1].sort(key=lambda x:[num[x],x])
    hoge = []
    for i in range(N):
        hoge.append(card[i%2][i//2])
    flag = True
    for i in range(N-1):
        if num[hoge[i]] > num[hoge[i+1]]:
            flag = False
    if flag:
        huga = []
        count = 0
        for i in range(N):
            l = bisect.bisect_left(huga,hoge[i])
            huga.insert(l,hoge[i])
            count += i-l
        if count < ans:
            ans = count
if ans >= 10**9:
    print(-1)
else:
    print(ans)