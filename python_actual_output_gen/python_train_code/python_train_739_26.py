floor = input()

f = int(floor)

for i in range(1,11,1):
    f+=1
    if "8" in str(f):
        print(i)
        break