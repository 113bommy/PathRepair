mas = list(map(int, input().split()))
mas = mas + [mas[0], mas[1]]
res = 0
for i in range(3):
    res += 4 * ((mas[i] / mas[i + 1] * mas[i + 2]) ** 0.5)
print(round(res))
