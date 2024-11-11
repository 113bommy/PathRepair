s = input()
vowels = "aeiou"

k = s.replace(" ","").lower()

if k[len(k)-2] in vowels:
    print("Yes")
else:
    print("No")