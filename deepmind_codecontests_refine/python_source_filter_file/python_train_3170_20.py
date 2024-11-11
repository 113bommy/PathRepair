from collections import Counter
teams = []
n = int(input()) 
for x in range(n):
    s = input()
    teams.append(s)
c = Counter(sorted(teams) )
print (c)
for k,v in c.items() :
    if v == max(c.values()):
        print (k)