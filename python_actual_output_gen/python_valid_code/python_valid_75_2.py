_,*s=open(0)
for c in sorted(s[0]):print(c*min(t.count(c)for t in s),end='')