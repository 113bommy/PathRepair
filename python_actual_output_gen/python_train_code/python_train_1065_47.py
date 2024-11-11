W,B=0,0
for i in range(8):
    n=list(input())
    W=W+((n.count('Q'))*9 +(n.count('B')*3)+(n.count('R')*5)+(n.count('K')*3)+(n.count('P')*1))
    B=B+((n.count('q'))*9 +(n.count('b')*3)+(n.count('r')*5)+(n.count('k')*3)+(n.count('p')*1))
if W>B:
    print("White")
elif B>W:
    print("Black")
else:
    print("Draw")