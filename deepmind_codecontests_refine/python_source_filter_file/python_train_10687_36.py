n = input()
n = n.split()
n[0] = int (n[0])
n[1] = int (n[1])

for i in range(n[1]):
    if (n[0]%10) == 0:
        n[0] = n[0]/10
    else:
        n[0] = n[0]-1

print(n[0])
