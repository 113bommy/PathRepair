# https://codeforces.com/contest/686/problem/A
n, x = map(int, input().split())

upset = 0
for i in range(n):
    trade, amount = input().split()
    amount = int(amount)
    if trade == "+":
        x += amount
    else:
        if amount < x:
            x -= amount
        else:
            upset += 1
print(x, upset)
