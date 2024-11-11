p = list(map(int, input().split())).sort()
print('Yes' if p[0]+p[1]==p[2] else 'No')