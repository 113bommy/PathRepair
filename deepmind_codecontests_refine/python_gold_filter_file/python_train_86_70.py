p = list(map(int, input().split()))
p.sort()
print('Yes' if p[0]+p[1]==p[2] else 'No')