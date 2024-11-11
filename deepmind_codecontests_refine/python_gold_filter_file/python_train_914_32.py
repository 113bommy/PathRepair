input()
lis = list(map(int, input().split()))
print(len([n for i, n in enumerate(lis[1:]) if n >= max(lis[:i + 1])]) + 1)