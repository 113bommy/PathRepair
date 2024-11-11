[t,s,x]=[int(x) for x in input().split()]
x-=t
if x%s==0 or x%s==1 and x!=1 or x<=0:
    print("YES")
else:
    print("NO")