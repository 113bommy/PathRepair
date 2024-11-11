import math
m = input()
w = m.split()
for i in range(0,len(w)):
	w[i] = int(w[i])
n = w[0]
k = w[1]
l = w[2]
c = w[3]
d = w[4]
p = w[5]
nl = w[6]
np = w[7]
one = math.floor((k*l)/(n*nl))
two = math.floor((p)/(n*np))
thr = math.floor((c*d)/(n))
ans = int((min(one,two,thr)))
print(ans)