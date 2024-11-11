n,m,k = list(map(int,input().split()))
for _ in range(k):
    u,v = list(map(int,input().split()))
for _ in range(k):
    u,v = list(map(int,input().split()))
ans = ''
if n==1 or m==1:
    if n==1:
        print(2*m)
        print('L'*m+'R'*m)
    else:
        print(n*2)
        print('D'*n+'U'*n)
else:
    ans+='U'*n
    ans+='L'*m
    for i in range(n):
        for j in range(m):
            if i%2==0:
                ans+='R'
            else:
                ans+='L'
        if i+1<n:
            ans+='D'
    print(len(ans))
    print(ans)