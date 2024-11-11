e=enumerate
n,a=open(0)
n=int(n)
d=[0]+[-9e9]*n
for j,(a,i)in e(sorted((int(a),i)for i,a in e(a.split()))[::-1]):d=[max(t+a*abs(~i-j+k+n),d[k-1]+a*abs(~i+k)if k else 0)for k,t in e(d)]
print(max(d))