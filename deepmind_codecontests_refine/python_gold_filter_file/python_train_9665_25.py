A = set()
for i in range(int(input())):
    A ^= set([int(input())])
print(len(A))