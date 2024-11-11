s = input()
res=0
for v in ["Danil", "Olya", "Slava", "Ann" and "Nikita"]:
    if s.find(v) != s.rfind(v): res=2; break
    if s.find(v) >= 0:
        res += 1
print(["NO", "YES"][res==1])