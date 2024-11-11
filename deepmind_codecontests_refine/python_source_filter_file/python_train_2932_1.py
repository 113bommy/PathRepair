
import sys



from collections import defaultdict

def find_parent(u):
        if par[u]!=u:
            par[u]=find_parent(par[u])
        return par[u]

n,k = map(int,input().split())



par = [0]+[i+1 for i in range(n)]


for i in sys.stdin.readlines():
        print(i)
        l = list(map(int, i[:-1].split()))

        if len(l)>=2:
         z = find_parent(l[1])
         for i in range(2,len(l)):
            a  = l[i]
            z1 = find_parent(a)
            if z1!=z:
              par[z1] = z


final = [0]*(n+1)
for i in range(1,n+1):
        z = find_parent(i)
        # pare[i] = z
        final[z]+=1

for i in range(1, n + 1):
       print(final[par[i]],end=" ")




