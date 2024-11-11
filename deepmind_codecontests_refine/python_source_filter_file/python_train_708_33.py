a, b = map(int, input())
c = input()
print('Yes' if c[a] == '-' and c.count('-') == 1 else 'No')