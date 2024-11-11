word = str(input())
word = word.split(" ")
part = int(word[0])
times = int(word[1])
thing = str(input())
thing = thing.split(" ")
eli = 0
for n in range(part):
    thing[n]=int(thing[n])+times
    if thing[n]<5:
        eli+=1
print(int(eli/3))
