alpabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
n = int(input())
s = input()
ans = 26
genome = "ACTG"
for i in range(n-3):
    m = 0
    for j in range(4):
        m += min((alpabet.index(s[i+j]) - alpabet.index(genome[j]) + 26) % 26,\
             (alpabet.index(genome[j]) - alpabet.index(s[i+j]) + 26) % 26)
    ans = min(ans, m)
print(ans)

