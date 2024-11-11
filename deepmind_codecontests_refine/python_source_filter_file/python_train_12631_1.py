n,m=map(int,input().split())
st=set()
sign=True
for i in range(0,n):
    a=set(input());
    if len(a)!=1 or a==st:
        sign1=False
        break
    st=a
print("YES" if sign else "NO")

