a = int(input())
b = input()
c = 0
for i in range(1,a):
    if b[i] == b[i - 1]:
        c += 1
print(c)
