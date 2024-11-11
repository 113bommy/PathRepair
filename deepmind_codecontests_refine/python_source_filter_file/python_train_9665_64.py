a = set()
for _ in range(int(input())):
    a ^= {int(input())}
print(len(a))