n,m=map(int,input().split())
a=[]
for i in range(n):
    b=list(map(int,input().split()))
    a+=b[1:]
for i in range(1,m+1):
    if i not in a:print('NO');exit()
print('YES')
