def q(a,k):
 d[a]=k
 for b in t[a]:
  if'-1'!=b:q(b,k+1)
def n(a,k):
 h[a]=max(h[a],k)if a in h else k
 if'-1'!=p[a]:n(p[a],k+1)
t,p,s,d,h={},{},{},{},{}
for _ in[0]*int(input()):
 x,y,z=input().split()
 t[x]=set([y,z])-{-1}
 p[y]=p[z]=x
 s[y],s[z]=z,y
r=(set(t)-set(p)).pop()
p[r]=s[r]='-1'
q(r,0)
for i in t:
 if not t[i]:n(i,0)
for i in map(str,sorted(map(int,t))):
 print(f"node {i}: parent = {p[i]}, sibling = {s[i]}, degree = {len(t[i])}, depth = {d[i]}, height = {h[i]}, {'root'if d[i]==0else'internal node'if t[i]else'leaf'}")
