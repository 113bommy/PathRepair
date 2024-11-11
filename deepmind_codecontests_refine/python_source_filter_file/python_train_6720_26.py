n=int(input())
sm=0
sc=0
se=0
for i in range(n):
    m,c=map(int,input().split())
    if m>c:
        sm=sm+1
    elif c>m:
        sc=sc+1
    elif c==m:
        se = se + 1
if sm>sc:
    print('Mishka')
elif sc>sm:
    print('Chris')
elif sm==sc:
    print('Friendship is magic^^')