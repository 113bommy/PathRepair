import re
length = int(input())
word = input()

regex = re.compile(word);
evolutions = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

for i in evolutions:
    ans = regex.match(i)
    if ans :
        print(ans.group())
        break

