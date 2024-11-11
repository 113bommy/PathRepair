n, n1, n2 = map(int, input().split())

lt = list(map(int, input().split()))

lt.sort(reverse = True)

#print(lt)

k1 = 0
k2 = 0
s1 = 0
s2 = 0

nMin = min(n1, n2)
nMax = max(n1, n2)

for i in range(nMin):
    s1 += lt[k1]
    k1 += 1
    
k2 = k1
for i in range(nMax):
    s2 += lt[k2]
    k2 += 1



s1 = round(s1 / k1, 8)
s2 = round(s2 / (k2-k1), 8)

print('{:.8f}'.format(s1+s2))
