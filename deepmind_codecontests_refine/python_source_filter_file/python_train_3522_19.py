(n,),*csf = [list(map(int, s.split())) for s in open(0)]

for j in range(n):
    t = 0
    for i in range(j,n-1):
        c,s,f = csf[i]
        t = max(t,s)
        t = s + ((t-s) // f * f)
        t += c
    print(t)