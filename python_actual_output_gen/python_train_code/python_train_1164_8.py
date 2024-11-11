a, b, s = (int(x) for x in input().split())
print('No' if (a + b + s) % 2 or a + b > s else 'Yes')
