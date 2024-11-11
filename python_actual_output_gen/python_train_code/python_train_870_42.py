a, b, c, d = map(int, input().split())

num1 = a//d
num2 = c//b

print('Yes' if num1>=num2 else'No')