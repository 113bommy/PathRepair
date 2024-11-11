n = int(input())
l = list(map(int, input().strip().split()))

even = 0
odd = 0

for i in range(n):
    if l[i] % 2 == 0:
        even += 1
    else:
        odd += 1

print(min(even, odd))