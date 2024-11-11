print(sum([input() not in [str(x) for x in range(18,2000)]+["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"] for e in range(int(input()))])) 
