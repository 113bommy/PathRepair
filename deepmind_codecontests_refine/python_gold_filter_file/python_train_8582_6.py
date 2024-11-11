import re

strLen = int(input())
name = input()

names = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]
for n in names:
    if re.search("^"+name+"$", n):
        print(n)
        break
