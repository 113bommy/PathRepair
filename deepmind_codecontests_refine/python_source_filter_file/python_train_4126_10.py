def digit_sum(n):
    num_str = str(n)
    sum = 0
    for i in range(0, len(num_str)):
        sum += int(num_str[i])
    return sum

n = int(input())
result = []
for i in range(1, 82):
    x = n - i
    if x > 0 and digit_sum(x) == i:
        result.append(x)

print(len(result))
if len(result) > 0:
    print(*result, sep='\n')