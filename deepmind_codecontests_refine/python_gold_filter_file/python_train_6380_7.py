for s in[*open(0)][1:]:
    p,q=map(int,s.split())
    l=[];j=2;a=q
    while(j*j<=a):
        if a%j==0:
            l+=[j]
            while(a%j==0):a//=j
        j+=1
    if a>1:l+=[a];a=1
    for j in l:
        k=p
        while(k%q==0):k//=j
        a=max(k,a)
    print(a)
