n,k=map(int,input().split())
*s,=input()
g=[]
t=1
for i in range(1,n):
 if s[i]==s[i-1]:t+=1
 else:g.append(t);t=1
g.append(t)
for i in range(1,len(g)):g[i]+=g[i-1]
g=[0]+g+[g[-1]]
print(max(g[i]-g[max(0,i-2*k-1)]for i in range(s[0]=='1',len(g),2))