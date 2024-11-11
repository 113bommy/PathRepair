n = int(input())
s = [int(x) for x in input().split()]
somas = {}
most = 0

for i in range(n-1):
    for j in range(i+1, n):
        soma = s[i]+s[j]
        if soma in somas:
            somas[soma] += 1
        else:
            somas[soma] = 1

print(max(somas))