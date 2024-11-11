a = set()
for _ in range(int(input())):
    a ^= {input()}
print(len(a))