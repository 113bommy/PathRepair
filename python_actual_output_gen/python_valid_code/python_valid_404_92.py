
n = int(input())

count = 0

for i in range(n):
    a, b = input().split()
    if int(a) < int(b):
        count += 1

print(count)