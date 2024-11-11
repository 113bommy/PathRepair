s1 = input()
s2 = input()

p = ""
subs1 = set()
for c in s1:
    p += c
    if p * (len(s1) // len(p)) == s1:
        subs1.add(p)
p = ""
subs2 = set()
for c in s2:
    p += c
    if p * (len(s2) // len(p)) == s2:
        subs2.add(p)
print(len(subs1 & subs2))
