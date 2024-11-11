for s in[*open(0)][1:]:
 n=int(s);i=2
 while i*i<=n and n%i:i+=1
 a=n%i>0 or n//i;print(+a,n-a)