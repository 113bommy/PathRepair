inputs = list(map(int,input().split()))
people = inputs[0]
pens = inputs[1]
notebooks = inputs[2]

if pens > people or notebooks > people:
    print ("Yes")
else: print ("No")