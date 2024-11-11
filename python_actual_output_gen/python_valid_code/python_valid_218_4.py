a,b,c = map(int,input().split())
k = int(input())

for i in range(k):
    if b < a:
        b*=2
    else:
        c*=2
if c>b>a:
    print('Yes')
else:
    print('No')