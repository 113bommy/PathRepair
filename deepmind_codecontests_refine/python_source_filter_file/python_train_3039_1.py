def replace(i, right_s):
    j = i + 1
    while j < n and s[j] != right_s:
        j += 1
    else:
        for k in range((j - i + 1) // 2):
            s[i + k], s[j - k] = s[j - k], s[i + k]
    return j

t = int(input())
operations = []
for _ in range(t):
    n, k = input().split()
    n = int(n)
    k = int(k)
    s = list(input())
    operations.append([])
    for i in range(n):
        if i < 2 * k:
            if i % 2 and s[i] == '(':
                operations[_].append([i, replace(i, ')')])
            elif i % 2 == 0 and s[i] == ')':
                operations[_].append([i, replace(i, '(')])
        elif i < n // 2 + k and s[i] == ')':
            operations[_].append([i, replace(i, '(')])
        elif i >= n // 2 + k and s[i] == '(':
            operations[_].append([i, replace(i, ')')])
for i in range(t):
    print(len(operations[i]))
    for operation in operations[i]:
        print(operation[0] + 1, operation[1] + 1)
