kata = input().lower()
res = ""
vowels = ["a","i","u","e","o"]
for char in kata:
    if char in vowels:
        pass
    else:
        res = res+"."+char

print(res)
print()