k = 0

x = int(input())
b = str(bin(x))[2:]
n = len(b)
print(b)
mas = []
while '0' in b:
    k +=2
    g = n - b.index('0')
    #print(g)
    b = str(bin(int(b, 2) ^ int('1' * g, 2)))[2:]
    if '0' in b:
        b = str(bin(int(b, 2) + 1))[2:]
    else:
        k -= 1
    #print(b)
    mas.append(g)
print(k)
print(*mas)