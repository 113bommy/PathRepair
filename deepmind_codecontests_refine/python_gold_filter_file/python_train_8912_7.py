# Love u atreyee!! Stay happy and blessed
n = int(input())
bal = [0] * (n + 1)
s = input()
zero = 0
one = 0
for i in range(n):
    if s[i] == "0":
        zero += 1
    else:
        one += 1
    bal[i+1] = zero - one
minInd = {}
for i in range(n+1):
    x = bal[i]
    y = minInd.get(x, n+1)
    minInd[x] = min(y, i)
ans = 0
for i in range(n+1):
    ans = max(ans, i - minInd[bal[i]])
print(ans)
