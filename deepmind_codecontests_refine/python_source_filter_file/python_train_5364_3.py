import re
a = re.split(' ', input())
p = int(a[1])
buyers = []
for i in range(0, int(a[0])):
    if (input() == 'half'):
        buyers.append(True)
    else:
        buyers.append(False)

c = 0
x = 0
for i in range(len(buyers)-1, -1, -1):
    if (buyers[i] == False):
        x = 2*x + 1
    else:
        x = 2*x
    c += p*x/2
print(c)
