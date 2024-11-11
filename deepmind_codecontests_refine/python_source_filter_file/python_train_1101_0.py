b,q,l,m = map(int,input().split())

bad = set(int(x) for x in input().split())

c = 0
n = b
done = False
for i in range(50):
    if abs(n) > l:
        done = True
        break
    if n not in bad:
        c += 1
    n = n*q

c1 = 0
n = b
for i in range(70):
    if abs(n) > l:
        break
    if n not in bad:
        c += 1
    n = n*q

if done or c == c1: print(c)
else: print("inf")
