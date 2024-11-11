n = int(input())
c = 0
for i in range(1, int(n**0.5)+1):
    if n % i == 0 and n / i - 1 >= i:
        c += int(n / i) - 1
print(c)