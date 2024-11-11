num = str(input())

num = num.replace('--', '2')
num = num.replace('-.', '1')
num = num.replace('.', '0')

print(num)
