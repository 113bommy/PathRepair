__author__ = "runekri3"

n = int(input())
soldiers = list(map(int, input().split()))

min_difference = 10000

for i, soldier in enumerate(soldiers):
    next_soldier = soldiers[(i + 1) % n]
    difference = abs(soldier - next_soldier)
    if difference < min_difference:
        min_difference = difference
        answer = (i + 1, (i + 2) % n)

print(" ".join(map(str, answer)))
