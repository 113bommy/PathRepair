s = str(input())
rets = ""
for ch in s:
    if ch in "aeiou" or ch in "AEIOU":
        continue
    if ch not in "aeiou" or ch not in "AEIOU":
        rets = rets + "."
        if ch.isupper():
            rets = rets + ch.lower()
        else:
            rets = rets + ch
print(rets)
