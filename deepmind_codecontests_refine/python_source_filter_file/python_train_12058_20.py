n = int(input())
w = [input() for i in range(n)]
f = 'Yes'
for i in range(n-1):
    if w[i][-1]!=w[i+1][0] or w[i] in w[:i]:
        f = 'No'
print(f)