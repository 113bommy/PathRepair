n = int(input())
languages = {}
l = list(map(int, input().split()))
for i in l:
    if i in languages:
        languages[i] += 1
    else:
        languages[i] = 1

m=int(input())
audio = list(map(int, input().split()))
subs = list(map(int, input().split()))

maxSoFar = (0, 0)
index = -1

for i,(a,s) in enumerate(zip(audio,subs), 1):
    current = 0
    if a in languages:
        current += 2*languages[a]

    if current < maxSoFar[0]:
        continue
    
    subt = 0
    if current == maxSoFar[0]:
        if s in languages:
            subt = languages[s]
        
        if subt > maxSoFar[1]:
            maxSoFar = (current, subt)
            index = i
    
    elif current > maxSoFar[0]:
        if s in languages:
            subt = languages[s]

        maxSoFar = (current, subt)
        index = i
print(index)
