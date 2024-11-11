w = input().lower()
n = 0
while True:
    t = input()
    if t == 'END_OF_TEXT': break
    n += t.lower().count(w)
print(n)