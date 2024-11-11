s = ['a', 'a', 'b', 'b']
n = int(input())
q = []
for i in range(n):
    q.append(s[i % 4])
print(*q, sep="")