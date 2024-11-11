value = input("")
for i in value:
    if i == "A":
       i = "a"
print(str(bin(int(value, 16)))[-1])