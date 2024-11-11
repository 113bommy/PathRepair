s = input()
variants = [s]
for i in range(1,len(s)):
    if s[i:]+s[:i] not in variants: variants += [s[i:]+s[:i]]
print(len(variants))