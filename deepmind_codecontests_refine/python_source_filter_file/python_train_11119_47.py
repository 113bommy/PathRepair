l = [int(input()) for _ in range(5)]
k = int(input())
print('Yay!' if max(l) - min(l) < k else ':(')