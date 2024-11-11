import bisect
MOD = 10**9+7
N,M = map(int,input().split())
A = sorted(list(map(int,input().split())))
B = sorted(list(map(int,input().split())))
a = set(A)
b = set(B)
check = True
if len(a) != N or len(b) != M:
    check = False
ans = 1
for num in range(N*M,0,-1):
    tmp = 0
    if num in A and num in B: continue
    elif num in A:
        tmp = M - bisect.bisect_left(B,num)
    elif num in B:
        tmp = N - bisect.bisect_left(A,num)
    else:
        x = bisect.bisect_left(A,num)
        y = bisect.bisect_left(B,num)
        tmp = (N-x)*(M-y) - (M*N-num) 
    
    if tmp < 0 or check == False:
        check = False
        break
    ans *= tmp
    ans %= MOD

print(ans if check else 0)