s = input()
cnt = 0
for el in ["Danil", "Olya", "Slava", "Ann", "Nikita"]:
    cnt += s.count(el)
print("YES" if cnt == 1 else "NO")