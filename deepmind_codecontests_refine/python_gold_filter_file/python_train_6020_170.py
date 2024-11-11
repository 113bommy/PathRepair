n = input()

print(n.translate(str.maketrans({"1":"9", "9":"1"})))