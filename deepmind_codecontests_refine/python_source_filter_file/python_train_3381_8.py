a,b,s=[int(w) for w in input().split()]
t=abs(a)+abs(b)
if t==s or t>s and (t-s)%2==0:
    print('YES')
else:
    print('NO')