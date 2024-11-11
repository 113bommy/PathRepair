def mi():
	return map(int, input().split())

def gcd(a,b):
    if b<a:
        a,b = b,a
    if a==0:
        return b
    return gcd(a,b%a)
n,k = mi()
a = list(mi())

g =0

for i in a:
    g = gcd(g,i)

t = g%k
ans = [t]
c = 1
t+=g
while True:
    if ans[0]==t%k:
        break
    ans.append(t%k)
    c+=1
    t+=g

print (c)
ans.sort()
for i in ans:
    print (i, end = ' ')
