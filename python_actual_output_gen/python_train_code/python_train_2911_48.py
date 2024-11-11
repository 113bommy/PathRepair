a = [1, 1]
while a[-1] < 10 ** 10:
    a.append(a[-1]+a[-2])

n = int(input())
no = True
for i in a:
    for j in a:
        for k in a:
            if i + j + k == n and no:
                print(i, j, k)
                no = False
if no:
    print("I'm too stupid to solve this problem")