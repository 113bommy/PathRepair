for s in[*open(0)][2::2]:
 a=[i for i,x in enumerate(s)if'1'<x];n=len(s)-1;r=n*(n+1)*['=']
 for i in range(n):r[(n+2)*i]='X';r[n*i+i+n]=' '
 for i,j in zip(a,a[1:]+a[:1]):r[n*i+i+j]='+';r[n*j+j+i]='-'
 print(*(['YES ',*r],['NO'])[0<len(a)<3],sep='')