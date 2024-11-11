s = ['a', 'b', 'b']
n = int(input())
q = []
for i in range(n):
    q.append(s[i % 3])
print(*q, sep="")