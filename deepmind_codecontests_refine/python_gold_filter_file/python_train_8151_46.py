n,k,l,c,d,p,nl,np = map(int,input().strip().split())
drink = k*l
drink //= nl
salt = p // np
print(min([salt//n,drink//n,(d*c)//n]))