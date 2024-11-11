n = int(input())
l = [0] + list(map(int, input().split()))
i = 1
curr = 0
while i != n + 1 and l[i] - curr <= 15:
    curr = l[i]
    i += 1
print(min(90, l[i - 1] + 15))