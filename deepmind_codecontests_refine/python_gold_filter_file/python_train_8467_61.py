n = int(input())
f = []
a, b = 0, 1
while a <= n:
    f.append(a)
    a, b = b, a + b
for i in f:
    for j in f:
        for k in f:
            if i + j + k == n:
                print(i, j, k)
                exit()
print("I'm too stupid to solve this problem")
