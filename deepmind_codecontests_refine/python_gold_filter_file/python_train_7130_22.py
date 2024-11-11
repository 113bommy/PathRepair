drink = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE",'0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17']
ans = 0
for i in range(int(input())):
    s = str(input())
    if s in drink:
        ans = ans +1
print(ans)        