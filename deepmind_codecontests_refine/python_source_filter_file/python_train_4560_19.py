k,*t=[map(int,t.split())for t in open(0)]
A,F=map(sorted,t)
o=10**12
g=-1
while~g+o:
 m,l=o+g>>1,k[1]
 for a,f in zip(A,F[::-1]):l-=max(0,a-m//f)
 if l<0:g=m
 else:o=m
print(o)