n = int(input())
numOdd = 0
minOdd = 99999999
s = 0
l = input().split(" ")
for i in range(n):
    a = int(l[i])
    if a%2 == 1:
        minOdd = min(minOdd, a)
        numOdd += 1
    s += a
if numOdd%2 == 0:
    print(s)
else:
    print(s-minOdd)
