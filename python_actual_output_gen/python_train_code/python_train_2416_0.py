a,b,c=(int(i) for i in input().split())

if a-b > 0:
    if a-b > c:
        ans='+'
    else:
        ans='?'
if a-b == 0:
    if c==0:
        ans=0
    else:
        ans='?'
if a-b < 0:
    if b-a > -c:
        ans='-'
    else:
        ans='?'
print(ans)
