n,l =map(int, input().split())
s = [input(i) for i in range(n)]
s.sort()
print(''.join(s))