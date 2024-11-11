n = input()
if "0" in n:
    n = n.replace("0","",1)
else:
    n = n.replace("1","",1)
print(n)