A=[int(input()) for _ in range(5)]
k=int(input())
print('Yey!' if max(A)-min(A)<=k else ':(')