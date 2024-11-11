a = input()
b = ""


for i in a:
    if i not in "aeiouAEIOU":
        b += "."
        b += i.lower()
print(b)
