s=input()
n = len(s)
vowels = ["a", "e", "i", "o", "u"]
if n < 3:
    print(s)
    exit()
dp = s[:2]
for i in range(2, n):
    x = s[i]
    if x in vowels:
        dp += x
    else:
        if dp[-1] == dp[-2] == x:
            dp += x
        elif (dp[-1] != " " and dp[-2] != " ") and (dp[-1] not in vowels) and (dp[-2] not in vowels):
            dp += " " + x
        else:
            dp += x
print(dp)
