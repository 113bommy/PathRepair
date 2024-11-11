n = int(input())
string = input()
numbers = [int(x) for x in string.split()]
socks = []
s = 0
table = [0 for x in range(n)]
for x in numbers:
    if table[x - 1] == 0:
        table[x - 1] = 1
        s += 1
    else:
        table[x - 1] = 0
        s -= 1
    socks.append(s)
print(max(socks))