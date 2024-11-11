a,b=map(int,input().split())
s_count=0
d_count=0
if a>=b:
    s_count=b
    a-=b
    if a>1:
        d_count=a//2
elif b>a:
    s_count=a
    b-=a
    if b>1:
        d_count=b//2
print(s_count,d_count)