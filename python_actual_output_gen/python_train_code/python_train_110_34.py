import math

nxy = list(input().rstrip().split(" "))
z = input()
n = nxy[0]
x = nxy[1] 
y = nxy[2]

k = int(x)
j = int(y)
i1 = z[-k+1:]
tmp = 10**(k) + 10 ** j
i2 = str(tmp)[1:-1]
count = 0
for i in range(len(i1)):
    if(i1[i] != i2[i]):
        count += 1

print(count)