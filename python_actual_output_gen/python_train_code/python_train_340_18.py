# https://codeforces.com/problemset/problem/155/A

kol = int(input())
scores = [int(i) for i in input().split()]
counter = 0
maxim = scores[0]
minim = scores[-1]

for elem in scores:
    if elem > maxim:
        counter +=1
        maxim = elem

    elif elem < minim:
        counter +=1
        minim = elem

print(counter-1)


