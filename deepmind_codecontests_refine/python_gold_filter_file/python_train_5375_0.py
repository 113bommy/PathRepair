def factorise(n):
    dic={} 
    while n%2==0:
        if 2 in dic:
            dic[2]+=1
        else:
            dic[2]=1
        n=n/2
        
    for i in range(3,int(n**0.5)+1):
        while n%i==0:
            if i in dic:
                dic[i]+=1
            else:
                dic[i]=1
            n=n/i
    if n>2:
        dic[n]=1
    return dic
def lcm(a,b):
    x =factorise(a)
    y =factorise(b)
    all_fac= list(set(list(x.keys())+list(y.keys())))
    pro =1
    for i in all_fac:
        if i in x and i in y:
            pro *= i**max(x[i],y[i])
        elif i in x:
            pro *= i**(x[i])
        elif i in y:
            pro *= i**(y[i])
    return pro
    
a,b = map(int,input().split())
dasha =0
masha = 0
lcm = lcm(a,b)
if a>b:
    dasha = lcm//a
    masha = (lcm//b)-1
elif b>a:
    dasha = (lcm//a)-1
    masha = (lcm//b)
else:
    print('Equal')

if dasha>masha:
    print('Dasha')
elif masha>dasha:
    print('Masha')
else:
    print('Equal')

    
