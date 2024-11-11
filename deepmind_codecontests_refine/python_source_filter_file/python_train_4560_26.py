N,K = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))
A.sort()
F.sort(reverse=True)
#二分探索をつくる
L = -1
R = 10**6 +1 
while R-L>1:
    Mid = (L+R)//2
    tmp = 0
    for a,f in zip(A,F):
        tmp += max(0, a-Mid//f)
    if tmp<=K:
        R = Mid
    else:
        L = Mid
print(R)