input()
data = input()
data = data.split()
for i in range(len(data)):
    data[i] = int(data[i])

mode = 0
for i in data[0:3]:
    if (i%2) :
        mode += 1
    else:
        mode -= 1

if mode > 0:
    mode = 1
else: mode = 0

for i in range(len(data)):
    if data[i]%2 == mode:
        print(i+1)
        break