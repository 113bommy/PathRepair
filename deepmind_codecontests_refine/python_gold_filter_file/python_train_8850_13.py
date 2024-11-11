w = input().lower()
t = 0
while True:
    s = input()
    if s == "END_OF_TEXT":
        break
    t += s.lower().split().count(w)
print(t)