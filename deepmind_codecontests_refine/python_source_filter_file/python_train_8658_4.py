data = [int(a) for a in input().split()]

maxim = 1 << (data[1] - 1)

a = 0
count = data[0]

while(count):
    a += maxim
    if (maxim > 2):
        maxim = maxim >> 2 
    else:
        maxim = 1
    count -= 1

maxim = 1 << (data[2] - 1)
minis = 1

b = 0
count = data[0]

while(count):
    b += minis
    if (minis >= maxim):
        minis = maxim
    else:
        minis = minis << 1
    count -= 1

print(a, b)
