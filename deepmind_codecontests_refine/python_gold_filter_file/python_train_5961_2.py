no = int(input())
print(4 + no*3)
print("1 0\n0 1\n1 1\n0 0")
for i in range(1, no+1):
    print(i, i+1)
    print(i+1, i)
    print(i+1, i+1)