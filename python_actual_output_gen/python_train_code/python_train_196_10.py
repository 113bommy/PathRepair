import sys
I = lambda : map(int,sys.stdin.readline().split())
n , m , k = I()
d = {}
pi = list(I())
li = list(I())
l1 = [0 for i in range (m+1)]
for i,j in enumerate(li) :
    d[j]=d.get(j,[])+[pi[i]]
#print(d)
la = list(I())
for i in la :
    p = pi[i-1]
    t = li[i-1]
    c = 0 
    for j in d[t] :
        if j > p :
            c+=1
    l1[t] = max(l1[t],c)
c= 0 
#print(l1)
for i in l1 :
    c+=i
print(c)