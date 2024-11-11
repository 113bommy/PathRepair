S=input()

judge = "AC" if (S[0] == 'a' and S[2:-1].count('C') == 1 and S[1:].replace('C', '').islower()) else "WA"
print(judge)