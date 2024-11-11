name = input()
se = set()
for i in name:
    se.add(i)
if len(se) %2:
    print("IGNORE HIM")
else:
    print("CHAT WITH HER")