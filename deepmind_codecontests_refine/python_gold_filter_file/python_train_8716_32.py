n = int(input())
d = {"red":0,"green":0,"purple":0,"blue":0,"yellow":0,"orange":0}
ans = 0
for i in range(n):
    val = input()
    d[val] = 1
    ans+=1
an = {"red":"Reality","green":"Time","purple":"Power","blue":"Space","yellow":"Mind","orange":"Soul"}
print(6-ans)
for i in d:
    if d[i]==0:
        print(an[i])

