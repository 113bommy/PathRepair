n = int(input())
gate = input()
monedas = 0
y = 0
x = 0
for i in range(n-1):
    if gate[i].upper() == "U":
        y+=1
    else:
        x+=1
    if x==y:
        if gate[i]==gate[i+1]:
            monedas+=1
print(monedas)