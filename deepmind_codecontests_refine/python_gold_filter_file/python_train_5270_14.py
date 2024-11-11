s = input()
k = 0
d = 0
vowels = "aeiou"
res = ""
lc=" "
for c in s:
    if not c in vowels:
        k += 1
        if c == lc:
            d += 1
            
        if (k - 1 != d and k >= 3):
            c != lc
            res += " "
            k = 1
            d = 0
    else:
        d = 0
        k = 0
    res += c
    lc = c
print(res)
