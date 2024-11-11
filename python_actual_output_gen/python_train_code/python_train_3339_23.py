a = set()
for i in range(int(input())):
    a ^= set(input())
print(len(a))