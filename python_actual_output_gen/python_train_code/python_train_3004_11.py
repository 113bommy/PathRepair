n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse = True)
print('Yes' if a[m-1] >= 1/4/m else 'No')
