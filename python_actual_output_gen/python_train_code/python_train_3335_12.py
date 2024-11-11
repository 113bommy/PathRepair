N = int(input())
A = list(map(int,input().split()))
A.sort()
ans = 0
hoge = sum(A)
p = 0
for i in range(N-1):
    hoge -= A[i]*2
    if hoge > ans:
        ans = hoge
        p = i
print(ans)
hoge = A[0]
for i in range(p+1,N-1):
    print(hoge,A[i])
    hoge -= A[i]
print(A[N-1],hoge)
hoge = A[N-1] - hoge
for i in range(1,p):
    print(hoge,A[i])
    hoge -= A[i]