N=int(input());A=sorted((int(x),i)for i,x in enumerate(input().split()));t=[0]*N**2
for w in range(N):
 a,j=A[w]
 for l in range(N-w):r=l+w;p=a*abs(j-l);t[l*N+r]=max(p+t[(l+1)*N+r],a*abs(j-r)+t[l*N+r-1])if w else p
print(t[N-1])