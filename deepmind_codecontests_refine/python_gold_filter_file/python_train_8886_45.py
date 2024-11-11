a = input()
b = input()
c = 0
for i in range(len(b)-1):
    if b[i] == b[i+1]:
        c += 1
print(c)