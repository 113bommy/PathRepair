for s in[*open(0)][1:]:
 n=int(s);*a,=range(1,n+1)
 for i in range(1,2,n):a[i-1],a[i]=a[i],a[i-1]
 if n%2:a[-1],a[-3]=a[-3],a[-1]
 print(*a)