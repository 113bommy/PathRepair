n = int(input())
a = list(map(int, input().split()))
print('Yes' if n % 2 and a[0] % 2 and a[-1] % 2 else 'No')