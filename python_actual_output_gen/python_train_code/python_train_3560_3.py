n, v = map(int, input().split())
s = []
for i in range(n):
    if v > min(map(int, input().split()[1: ])):
        s.append(str(i))
print(len(s))
print(' '.join(s))