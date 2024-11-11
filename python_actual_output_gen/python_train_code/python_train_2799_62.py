n,k,l,c,d,p,nl,np=map(int,input().split())
s1=(k*l)//n
s2=c*d
s3=p//n
print(min(s1,s2,s3)//n)