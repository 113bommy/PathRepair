k = int(input())
numb = '6' * (k % 2) + '8' * (k // 2)
print(numb if len(numb) < 19 else -1)
