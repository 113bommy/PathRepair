s = input()
vow = ['a','e','i','o','u']
for i in s:
    if i.lower() not in vow:
        print("."+i.lower(),end="")
    