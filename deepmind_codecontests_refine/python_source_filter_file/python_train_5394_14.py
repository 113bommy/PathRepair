n = int(input())
l =[int() for i in input().split()]
print('Yes' if max(l) < sum(l) - max(l) else 'No')