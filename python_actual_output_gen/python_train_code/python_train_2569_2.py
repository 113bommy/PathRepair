n , d = map(int,input().split())
a = list(map(int,input().split()))
m = int(input())


if m <= n :
    profit = sum(a[:m])
    print(profit)
else:
    profit = sum(a[:n])
    profit -= ((m-n)*d)
    print(profit)       