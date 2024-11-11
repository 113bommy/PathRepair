n = int(input())
ans = 0
for i in range(n):
    ans += eval(input().replace(" ","*").replace("JPY","1").replace("BTC","380000"))
print(int(ans))