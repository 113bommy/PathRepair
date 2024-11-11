Time = input().split()
Work = input().split()
days = int(Time[0])
reading = int(Time[1])
i = 0
while reading != 0:
    reading -= 86400 - int(Work[i])
    i += 1
    if i == len(Work):
        break
print(i)
