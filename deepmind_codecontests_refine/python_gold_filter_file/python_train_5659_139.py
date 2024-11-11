s = input()
licznik = 0
slowo = ""
for i in range(len(s)):

    if licznik > 0 and licznik < 3:
        licznik += 1
        continue
    else:
        licznik = 0
    if s[i:i+3] == "WUB":
        licznik += 1
        continue
    #print(s[i])
    slowo += s[i]
    if s[ i+1: i + 4] == "WUB":
        slowo += " "
print(slowo)