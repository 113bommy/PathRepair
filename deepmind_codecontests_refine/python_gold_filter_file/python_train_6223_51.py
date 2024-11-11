s,t=open(0)
print(min(sum(a!=b for a,b in zip(s[i:],t[:-1]))for i in range(len(s)-len(t)+1)))