s = input()
s = s.replace("eraser", "").replace("dreamer", "").replace("erase", "").replace("dream", "")
print("YES") if s == "" else print("NO")