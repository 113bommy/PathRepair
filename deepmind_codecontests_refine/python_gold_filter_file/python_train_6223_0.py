s,t=open(0)
print(min(sum(x!=y for x,y in zip(s[i:],t[:-1]))for i in range(len(s)-len(t)+1)))