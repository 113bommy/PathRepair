N=[]
for _ in range(int(input())):
	N.append([int(x) for x in input().split(" ")])
for n in N:
    f,s,t=sorted(n[:3])
    m=n[-1]
    fmin,fmax=[max(s-(f+1),0),max(0,f-1+s-1)]
    lmin,lmax=[max(0,t-(s+f+1)),max(0,t-1+fmax)]
    if lmin<=m<=lmax:
        print("YES")
    else:
        print("NO")