valid_drinks = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]

no_of_customers = int(input())

customers = [input() for i in range(no_of_customers)]

drinks = [i for i in customers if i.isalpha()]
age = [int(i) for i in customers if not i.isalpha()]

restricted_drinks = len([i for i in drinks if i in valid_drinks])
restricted_age = len([i for i in age if i in range(18)])

print(restricted_drinks + restricted_age)
