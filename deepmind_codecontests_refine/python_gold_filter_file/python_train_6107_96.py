total = 1
players = input()
dang = False
last = ""
for p in players:
    if p == last:
        total += 1
    else:
        total = 1

    if total == 7:
        dang = True
    last = p

if dang:
    print("YES")
else:
    print("NO")
