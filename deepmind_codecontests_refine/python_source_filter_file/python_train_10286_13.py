n = int(input())
l = [int(i) for i in input().split()]
mis = 0
for i in range(n):
    if l[i] != i:
        mis += 1
print('YES' if mis<3 else 'NO')