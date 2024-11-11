nabcd = list(map(int, input().split()))
RANGE = range(1,nabcd[0])
a = nabcd[1]
b = nabcd[2]
c = nabcd[3]
d = nabcd[4]
dif1 = a-d
dif2 = b-c
dif = abs(dif1) + abs(dif2)
counter = nabcd[0]*(nabcd[0]-dif)
print(max(counter,0))

