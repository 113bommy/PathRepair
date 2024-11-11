n = int(input()) + 1
for i in range(n): print((' ' * ((n - i) + 1 // 2) * 2 + ' '.join([str(j) for j in range(i)]) + ' ' + ' '.join(reversed([str(j) for j in range(i - 1)]))).rstrip())
for i in reversed(range(n + 1)): print((' ' * ((n - i) + 1 // 2) * 2 + ' '.join([str(j) for j in range(i)]) + ' ' + ' '.join(reversed([str(j) for j in range(i - 1)]))).rstrip())
