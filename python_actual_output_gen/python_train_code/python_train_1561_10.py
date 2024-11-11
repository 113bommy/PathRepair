vowels = ["a", "e", "i", "o", "u"]
string = list(input().lower())
i = 0
n = len(string)
while i < n:
    if string[i] in vowels:
        string.remove(string[i])
        n -= 1
    else:
        i += 1
print("." + ".".join(string))

