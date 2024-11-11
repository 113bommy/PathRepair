a, b = map(int, input().split())
print(sum(map(lambda i: 1 if str(i) == str(i)[::-1] else 0, range(a, b+1))))