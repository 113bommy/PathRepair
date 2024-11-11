numbers = [2, 6, 2, 3, 3, 3, 2, 5, 1, 2]
n = input()
a = 1
for x in n:
    a *= numbers[int(x)]
print(a)
