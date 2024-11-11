mod = 1000003
"""
for i in range(2,57000):
    if n%i==0:
        print("nonPrime")
        exit()
print("prime")
"""
q = int(input())
fct = [0]
tmp = 1
for i in range(1,mod+3):
    tmp *=i
    tmp%=mod
    fct.append(tmp)
for i in range(q):
    x,d,n = map(int, input().split( ))
    if d%mod == 0:
        print(pow(x,mod-2,mod))
        continue
    if n>=mod:
        print(0)
        continue
    rev_d = pow(d,mod-2,mod)
    x*=rev_d
    x%=mod
    tmp = pow(d,n,mod)
    try:
        tmp*=fct[x+n-1]
    except:
        print(0)
        continue
    if x>=2:
        tmp*=pow(fct[x-1],mod-2,mod)
    tmp%=mod
    print(tmp)
    
    
            