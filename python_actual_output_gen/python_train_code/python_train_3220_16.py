N,K=map(int,input().split())
x=list(map(int,input().split()))
tmin=1000000000
for i in range(N-K+1):
    a=x[i+K-1]
    b=x[i]
    res=a-b+min([abs(a),abs(b)])
    if tmin>a:
        tmin=a
print(tmin)