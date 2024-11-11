n = int(input())
x = 0
for i in range(4, n+1, 4):
    if (n - i) % 7 == 0:
        x = 1
print(('No','Yes')[x])