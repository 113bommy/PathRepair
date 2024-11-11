n, k =map(int, input().split())
t = input()
p = input().split()
r = [0]

for i in t:
    if i in p:
        r[-1] += 1
    else:
        r.append(0)

s = 0

for i in r:
    s += i*(i+1)/2

print(int(s))
