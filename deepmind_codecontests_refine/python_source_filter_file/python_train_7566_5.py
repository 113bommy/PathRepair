n = int(input())
x = list(input())
for i in range(n, 0, -1):
    if n % i == 0:
        x[:i+1] = x[i::-1]
print(''.join(x))