n, x, y = tuple(map(int, input().split()))
str = input()
num = 0
i = 0
while i < len(str):
    if str[i] == '0':
        j = i + 1
        num += 1
        while j < len(str) and str[j] == '0':
            j += 1
        i = j
    i += 1
if n*'1' == str:
    print(1)
else:
    if x <= y:
        print((num-1)*x+y)
    else:
        print(num*y)