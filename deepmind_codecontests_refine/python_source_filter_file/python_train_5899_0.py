s = input()

l = []

checked = True

for i in range(0, len(s)):
    l.append(s[i])

if sorted(l) != l:
    checked = False

n = {}

for letter in list(set(s)):
    n[letter] = l.count(letter)

if n.get("a") == None and n.get("b") == None:
    checked = False

if n.get("c") != n.get("a") and n.get("c") != n.get("b"):
    checked = False

if n.get("c") == None:
    checked = False

if checked:
    print("YES")
else:
    print("NO")
