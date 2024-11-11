n = int(input().strip())

n_array = []

for x in range(n):
    n_array.append(input().strip().split())

vals = {}
for x in range(len(n_array)):
    for y in range(6):
        vals[int(n_array[x][y])] = 1
if n == 2:
    for p in range(6):
        for y in range(6):
            num = str(n_array[0][p])
            num += str(n_array[1][y])
            vals[int(num)] = 1
            num = str(n_array[1][y])
            num += str(n_array[0][p])
            vals[int(num)] = 1

elif n == 3:
    for p in range(6):
        for y in range(6):
            num = str(n_array[0][p])
            num += str(n_array[1][y])
            vals[int(num)] = 1
            num = str(n_array[1][y])
            num += str(n_array[0][p])
            vals[int(num)] = 1
            num = str(n_array[0][p])
            num += str(n_array[2][y])
            vals[int(num)] = 1
            num = str(n_array[2][y])
            num += str(n_array[0][p])
            vals[int(num)] = 1
            num = str(n_array[1][p])
            num += str(n_array[2][y])
            vals[int(num)] = 1
            num = str(n_array[2][y])
            num += str(n_array[1][p])
            vals[int(num)] = 1
    for p in range(6):
        for y in range(6):
            for z in range(6):
                num = str(n_array[0][p])
                num += str(n_array[1][y])
                num += str(n_array[2][z])
                vals[int(num)] = 1
                num = str(n_array[0][p])
                num += str(n_array[2][y])
                num += str(n_array[1][z])
                vals[int(num)] = 1
                num = str(n_array[1][p])
                num += str(n_array[0][y])
                num += str(n_array[2][z])
                vals[int(num)] = 1
                num = str(n_array[1][p])
                num += str(n_array[2][y])
                num += str(n_array[0][z])
                vals[int(num)] = 1
                num = str(n_array[2][p])
                num += str(n_array[1][y])
                num += str(n_array[0][z])
                vals[int(num)] = 1
                num = str(n_array[2][p])
                num += str(n_array[0][y])
                num += str(n_array[1][z])
                vals[int(num)] = 1

for x in range(1,999):
    if x not in vals:
        print(x-1)
        break