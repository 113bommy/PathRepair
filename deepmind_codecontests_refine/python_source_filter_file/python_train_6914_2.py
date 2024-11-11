n = int(input())
string = input()
coins = list(map(int, string.split()))
s = ""
for x in range(n):
    a = coins[x]
    if a == n - 1:
        s += "PLR" * (a - 1)
    else:
        s += "PRL" * (a - 1)
    if a > 0:
        s += "P" 
    if x < n - 1:
        s += "R"
print(s)