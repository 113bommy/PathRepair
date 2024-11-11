import sys
result = 0
n = 0
for answer in sys.stdin:
    if answer[0] == '+':
        n += 1
    elif answer[0] == '-':
        n -= 1
    else:
        result += n * len(answer.split(':')[1])
print(result)


