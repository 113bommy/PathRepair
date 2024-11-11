n = int(input())
a = list(map(int, input().split()))
answers = []
summa = 0
if a[0] == 1:
    answers.append(2)
else:
    if a[0] % 2 == 0:
        answers.append(2)
    else:
        answers.append(1)
    summa += a[0] - 1
for i in range(1, n):
    v = a[i]
    if v == 1:
        answers.append(answers[-1])
        continue
    summa += v - 1
    if summa % 2 == 0:
        answers.append(2)
    else:
        answers.append(1)
for i in range(n):
    print(answers[i])
