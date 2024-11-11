'''input
2 3 4
'''
a, b, c = sorted(map(int, input().split()))
print((b+1)*(c+1) - a*(a-1))