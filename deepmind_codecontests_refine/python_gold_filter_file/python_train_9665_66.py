a = set()
for i in range(int(input())):
    a ^= {input()}
print(len(a))