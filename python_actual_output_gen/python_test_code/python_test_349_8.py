n,t,k,d = map(int,input().split(" "))
m = n//k
oven1 ,oven2 = 0,d
for i in range(m):
    if oven1<=oven2:
        oven1+=t
    else:
        oven2+=t

if max(oven1,oven2)>=(m*t):
    print("NO")
else:
    print("YES")
