st = input()
works = True
for i in st:
    if(i != "1" and i != "4"):
        works = False
if(st[0] != "1"):
    works = False
for i in range(len(st) - 3):
    if(st[i] == "4" and st[i + 1] == "4" and st[i + 2] == "4"):
        works = False
        break
if(works):
    print("YES")
else:
    print("NO")
