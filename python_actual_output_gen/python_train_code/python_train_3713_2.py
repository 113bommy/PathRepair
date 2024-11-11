N = int(input())
S = input()

m = 0
for i in range(1, N):
    m = max(m, S[:i].count('I') - S[:i].count('D'))
print(m)
