li = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
j = 11
ans = 0
n = int(input())
for i in range(n):
    x = input()
    for j in range (11):
        if(x == li[j]):
            ans = ans + 1
            break
    if(x[0] <= '9' and x[0] >= '1'):
        m = int(x)
        if(m < 18):
            ans = ans + 1
            continue

print(ans)
