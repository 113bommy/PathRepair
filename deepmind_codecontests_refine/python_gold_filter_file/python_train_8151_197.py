n,k,l,c,d,p,nl,np=[int(x) for x in input().split()]
total_ml=(k*l)//nl
lime=(c*d)
salt=p//np
ans=(min(total_ml,lime,salt))//n
print(ans)