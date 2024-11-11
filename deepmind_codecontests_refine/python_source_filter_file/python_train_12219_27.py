n = int(input())
l = list(map(int,input().split()))
ch = 0
bi = 0
ba = 0
h = 0
for f in range(n) :
    h += 1
    if h == 4 : h = 1
    if h == 1 : ch += l[f]
    elif h == 2 : bi += l[f]
    else : ba += l[f]
if ch > bi and ch > ba : print("chest")
if bi > ch and bi > ba : print("biceps")
else : print("back")
