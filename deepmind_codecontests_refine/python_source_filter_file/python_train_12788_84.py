A,B,C,D,E,F=map(int,input().split())
water=set({})
for i in range(F//(100*A)+1):
    for j in range(F//(100*B)+1):
        if 100*A*i + 100*B*j <= F:
            water|={100*A*i + 100*B*j}
sugar=set({})
for i in range(F//C+1):
    for j in range(F//D+1):
        if C*i + D*j <= F:
            sugar|={C*i + D*j}
water-=set({0})
max_=0
for w in water:
    for s in sugar:
        if w+s<=F and s*(100+E)<E*(w+s) and max_*(w+s)<=s:
            max_=s/(w+s)
            ans=[w+s,s]
print(ans[0],ans[1])