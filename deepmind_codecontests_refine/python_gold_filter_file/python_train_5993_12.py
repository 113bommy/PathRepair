i = int(input())
l = list(input())
longstnotinpar = 0
wordcount = 0
inparcount = 0
p = 0
for x in l:

    if x == '(':
        p = 1
        if wordcount > longstnotinpar: longstnotinpar = wordcount
        wordcount = 0
    elif x == ')':
        p =0
        if wordcount > 0: inparcount += 1; wordcount = 0

    elif p == 0:
        if x == '_':
            if wordcount > longstnotinpar: longstnotinpar = wordcount
            wordcount = 0
        else: wordcount += 1
    elif p == 1:
        if x == '_':
            if wordcount > 0: inparcount += 1; wordcount = 0
        else: wordcount += 1
if wordcount > longstnotinpar: longstnotinpar = wordcount; wordcount = 0
print(longstnotinpar, inparcount)