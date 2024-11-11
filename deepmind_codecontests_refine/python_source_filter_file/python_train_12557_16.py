n = int(input())
mas = []
for i in range(n - 10 * len(str(n)), n):
    if i < 1:
        continue
    if i + sum(list(map(int, str(i)))) == n:
        mas.append(i)
if len(mas) == 0:
    print(0)
else:
    print(len(mas))
    print("".join(list(map(str, mas))))