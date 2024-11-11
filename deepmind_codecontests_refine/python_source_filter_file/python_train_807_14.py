e=enumerate
n,a=open(0)
d=[0]+[-9e9]*2001
for j,(a,i)in e(sorted((-int(a),i)for i,a in e(a.split()))):d=[max(t-a*abs(~i-j+k+int(n)),d[k-1]-a*abs(~i+k))for k,t in e(d)]
print(max(d))