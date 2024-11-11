word = input()
d = u = s = False
for i in word:
    if i.isdigit() : d = True
    if i.isupper() : u = True
    if i.islower() : s = True
if d and u and s and len(word) >= 5:
    print("Correct")
else:
    print("Too Weak")