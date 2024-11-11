pya = int(input())
arre = []

while pya:
    pya -= 1
    arre.append(input().lower())

oString = input()
lowString = oString.lower()

letter1 = input()[0].lower()
letter2 = 'a' if letter1.lower() != 'a' else 'b'

valid = [0 for i in range(len(oString))]

setcito = set()

for x in arre:
    if lowString.find(x) >= 0:
        wat = 0
        while True:
            index = lowString.find(x, wat)
            if index < 0:
                break
            for i in range(index, index + len(x)):
                setcito.add(i)
            wat = index + len(x)

oString = list(oString)
for i in setcito:
    letter = letter1 if lowString[i] != letter1 else letter2
    oString[i] = letter if oString[i].islower() else letter.upper()

for x in oString:
    print(x, end="")
print()

"""
3
e
e
e
PetrLoveLuckyNumbersee
t

"""
