import re

n = int(input())
s = input()

forms = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon",
         "glaceon", "sylveon"]

for form in forms:
    if re.fullmatch(s, form) is not None:
        print(form)