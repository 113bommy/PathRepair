a,b,c,d = map(int, input().split())
print(["No","Yes"][a//d + (a%d > 0) >= b//c + (b%c > 0)])