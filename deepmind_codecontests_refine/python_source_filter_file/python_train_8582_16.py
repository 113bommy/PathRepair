import re
a = 'vaporeon, jolteon, flareon, espeon, umbreon, leafeon, glaceon, sylveon'
a = a.split(', ')
n = int(input())
s = input()
for pokemon in a:
    if re.search(s, pokemon):
        print(pokemon)
