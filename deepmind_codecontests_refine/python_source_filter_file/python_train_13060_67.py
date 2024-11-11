def urok(chislo):
    if chislo % 2 == 0 and chislo >=12:
        return 8, chislo - 2
    elif chislo % 2 != 0 and chislo >= 12:
        return 9, chislo - 9

a,b = urok(int(input()))
print(a, b)
        
