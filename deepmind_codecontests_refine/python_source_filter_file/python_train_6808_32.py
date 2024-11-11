num = str(input())

num = num.replace('-.', '1')
num = num.replace('.', '0')
num = num.replace('--', '2')


print(num)
