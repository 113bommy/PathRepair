# cook your dish here

n, m = [int(x) for x in input().strip().split()]


row = -1
colm = -1
start_row = -1


lastx = False
for _ in range(n):
    l = input()
    
    if "B" in l and not lastx:
        start_row = _
        lastx = True
    if "B" not in l and lastx:
        row = (_+start_row)//2+1
        lastx = False
    
    lastB = False
    for i in range(m):
        if l[i] == "B" and not lastB:
            col = i
            lastB = True
        if l[i] == "W" and lastB:
            colm = (i+col)//2+1
            lastB = False
            
            
if colm==-1:
    colm = (m+col)//2+1
    
if row==-1:
    row = (n+start_row)//2+1
print (row,colm,col)