alpha = [item for item in "abcdefghijklmnopqrstuvwxyz"]
string = input()
l = []
if abs(alpha.index(string[0])-alpha.index("a")) <= 13:
    l.append(abs(alpha.index(string[0])-alpha.index("a")))
elif abs(alpha.index(string[0])-alpha.index("a")) > 13:
    l.append(26-abs(alpha.index(string[0])-alpha.index("a")))

for item in range(0,len(string)-1):
    if abs(alpha.index(string[item +1]) - alpha.index(string[item])) <= 13:
        l.append(abs(alpha.index(string[item +1]) - alpha.index(string[item])))
    elif abs(alpha.index(string[item +1]) - alpha.index(string[item])) > 13:
        l.append(26-abs(alpha.index(string[item +1]) - alpha.index(string[item])))
print(l)