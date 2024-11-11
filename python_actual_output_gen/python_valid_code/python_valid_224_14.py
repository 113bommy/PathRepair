a,b,c,d,e,f=map(int,input().split())
l_water=set()
for i in range(f//(a*100)+1):
    for j in range(f//(b*100)+1):
        tmp=i*a*100+j*b*100
        if 0<tmp<=f:l_water.add(tmp)
l_sugar=set()
max_s=max(l_water)//100*e
for i in range(max_s//c+1):
    for j in range(max_s//d+1):
        tmp=i*c+j*d
        if 0<=tmp<=max_s:l_sugar.add(tmp)
ans=[0,0,0]
for i in l_water:
    for j in l_sugar:
        if j<=i//100*e and i+j<=f:
            tmp=j/(i+j)
            if tmp>ans[0]:
                ans=[tmp,i+j,j]
print(*ans[1:])