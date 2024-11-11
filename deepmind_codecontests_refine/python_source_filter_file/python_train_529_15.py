n, L, a = [int(s) for s in input().split()]
l = []
t = []
smokingTimes = 0
for i in range(n):
    d, k = [int(s) for s in input().split()]
    t.append(d)
    l.append(d+k)

for i in range(1, n-1):
    smokingTimes += (t[i+1] - l[i])//a

if n != 0:
    smokingTimes += t[0]//a
    smokingTimes += (L-l[-1])//a
else:
    smokingTimes = L//a
print(smokingTimes)