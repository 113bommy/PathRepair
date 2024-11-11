def winner(x,y):
    for i in y:
        if x == i:
            return True
    return False

def IsWinner(p,s): #Place and score
    i = (s//50) % 475
    for j in range(25):
        i = (i * 96 + 42) % 475
        if p==(i+26):
            return True
    return False
    

line = input()
p = int(line.split()[0])
x = int(line.split()[1])
y = int(line.split()[2])

a_up = 0
a = -1
found = False

cs = x
while(cs>y):
    if IsWinner(p,cs):
        a = 0
        break
    if IsWinner(p,cs+50):
        a = 1
    cs = cs - 50
cs = x
if (a==-1):
    while(True):
        a_up = a_up+1
        cs = cs + 100
        if IsWinner(p,cs) or IsWinner(p,cs-50):
            a = a_up
            break
print(a)
    
    
        
    
        



