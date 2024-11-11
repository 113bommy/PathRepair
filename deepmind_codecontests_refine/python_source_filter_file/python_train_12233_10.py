c = int(input())

for i in range(2, int(c**(1/2))):
    while c % (i*i) == 0:
        c = c / i

print(int(c))