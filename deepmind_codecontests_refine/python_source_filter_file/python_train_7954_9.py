s = input()
m = s.index('^')
f = lambda x: int(x) if x not in ['=','^'] else 0
k = sum(f(s[i])*(i+1-m) for i in range(len(s)))
print([['left','right'][0<k],'balance'][k==0])

#l,r = input().split('^')
#p,q = l.replace('=',''), r.replace('=','')
#a = sum(int(p[::-1][i])*(l[::-1].index(p[::-1][i])+1) for i in range(len(p)))
#b = sum(int(q[j])*(r.index(q[j])+1) for j in range(len(q)))
#print([['left','right'][a<b],'balance'][a==b])

#a = sum(int(l[::-1][i])*(i+1) for i in range(len(l)) if l[::-1][i] != '=')
#b = sum(int(r[j])*(j+1) for j in range(len(r)) if r[j] != '=')
#print([['left','right'][a<b],'balance'][a==b])
