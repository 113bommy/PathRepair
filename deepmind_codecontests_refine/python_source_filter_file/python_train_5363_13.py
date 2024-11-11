n, p, q = [int(e) for e in input().split(' ')]
s = input()
l = len(s)

solA = -1
solB = -1

for i in range(0, (l + p - 1) // p):
    if (l - p*i) % q == 0:
        solA = i
        solB = (l - p*i) // q
        break

if solA == -1:
    print(-1)
else:
    print(solA + solB)
    for i in range(0, solA):
        print(s[i*p:(i + 1)*p])
    for i in range(0, solB):
        print(s[(solA*p + i*q):(solA*p + (i + 1)*q)])
