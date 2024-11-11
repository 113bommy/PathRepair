x = [int(input()) for _ in range(5)]
k = int(input())
print(':(' if x[4] - x[0] > k else 'Yey!')