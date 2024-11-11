a,b=map(int,input().split())
x="a==b" if a==b else 1
if x==1:
    x="a>b" if a>b else "a<b"
print(x)

