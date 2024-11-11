from itertools import combinations

def findsum(comb):
    sum = 0
    for song in comb:
        sum += song[0]
    return sum

def finda(a,b,c):
    if a == 0:
        return 0
    if a == 1 and b == 0 and c == 0:
        return 1
    else:
        return (a * findb(a-1,b,c)+ a*findc(a-1,b,c))

def findb(a,b,c):
    if b == 0:
        return 0
    if b == 1 and a == 0 and c == 0:
        return 1
    else:
        return (b * finda(a,b-1,c)+ b*findc(a,b-1,c))

def findc(a,b,c):
    if c == 0:
        return 0
    if c == 1 and a == 0 and b == 0:
        return 1
    else:
        return (c * finda(a,b,c-1)+ c*findb(a,b,c-1))



n, T = map(int,input().split())
songs = []
total_combinations = 0
for i in range(n):
    t, g = map(int,input().split())
    songs.append([t,g])

for i in range(1, n+1):
    allcomb = list(combinations(songs,i))
    for comb in allcomb:
        sum = findsum(comb)

        if sum == T:
            a = 0
            b = 0
            c = 0
            for song in comb:
                if song[1] == 1:
                    a += 1
                elif song[1] == 2:
                    b += 1
                else:
                    c += 1
            total_combinations += finda(a,b,c)+findb(a,b,c)+findc(a,b,c)
total_combinations = total_combinations%1e7
print(total_combinations)