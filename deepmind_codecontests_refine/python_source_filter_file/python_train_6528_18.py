n, x, y = [int(x) for x in input().split()]
l = list(input())
l = ['1'] + l + ['1']
num = 0
for i in range(len(l) - 1):
    if l[i] == '1' and l[i + 1] == '0':
        num += 1
l = l[1:-1]
num1 = num * y
num2 = num * x - x + y
print(min(num1, num2))