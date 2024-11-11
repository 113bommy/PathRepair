a,b,c,d,e,f = map(int, input().split(' '))

w = 0
s = 0
ratio = 0

for i in range((f // (b*100))+1):
    for j in range(((f-(i*b*100))//a)+1):
        if i == 0 and j == 0:
            continue
        smax = min(f-(j*a+i*b)*100,(j*a+i*b)*e)
        sm = 0
        for k in range((smax//d)+1):
            sm = max(sm, k*d+c*((smax-(k*d))//c))
#        if ratio < sm/((j*a+i*b)*100+sm):
            ratio = sm/((j*a+i*b)*100+sm)
            w = (j*a+i*b)*100
            s = sm



print("%i %i" %(w+s,s))
