# a = list(map(int, input().strip().split()))

niz = input().strip().split()

I = niz[0]
P = niz[1]


s = I[0]
i = 1
while i < len(I) and I[i] < P[0]:
    s += I[i]
    i += 1
j = 0
s += P[0]

print(s)
