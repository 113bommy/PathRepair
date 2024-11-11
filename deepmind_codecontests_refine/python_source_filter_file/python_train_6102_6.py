n = int(input())
a = list(map(int, input().split()))
print('Yes' if n & a[0] & a[-1] else 'No')
