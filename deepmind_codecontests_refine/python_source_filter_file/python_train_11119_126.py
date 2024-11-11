a = [int(input()) for _ in range(5)]
k = int(input())
print(':(' if a[4] - a[0] > k else 'Yey!')