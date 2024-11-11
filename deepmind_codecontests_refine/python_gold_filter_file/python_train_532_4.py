n,m,k = map(int,input().split())
p = list(map(int, input().split()))
s = list(map(int, input().split()))
x = [0]*m
c = list(map(int, input().split()))
q = 0
for i in range(n):
    if x[s[i]-1]<p[i]:
        x[s[i]-1]=p[i]
for i in range(k):
    if not(p[c[i]-1] in x):
        q+=1
print(q)