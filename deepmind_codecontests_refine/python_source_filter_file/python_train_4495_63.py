vowels = "AOYEUIaoyeui"
word = input()
res = ""
for c in word:
    if c not in vowels:
        res += "." + c
print(res)