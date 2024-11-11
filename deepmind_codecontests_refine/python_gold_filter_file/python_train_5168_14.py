n = int(input())
s = input()
a = []
s = s.split()
mn = 1000000001
count = 0
minres = 100000
for c in s:
    if int(c)<mn:
        mn = int(c)
        minres = 100000
        count = 0
    if count!=0 and int(c)==mn:
        if count<minres:
            minres = count
        count=0
    count += 1
print(minres)