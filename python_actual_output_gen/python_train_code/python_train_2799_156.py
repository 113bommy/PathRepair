n,k,l,c,d,p,nl,np=[int(x) for x in input().split()]
total_ml=(k*l)//nl
lime=(c*d)//n
salt=p//np
ans=min(total_ml//n,lime,salt)//n
print(ans)