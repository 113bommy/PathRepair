
A,B = list(map(int,input().split()))

QA=(A-1)//50
QB=(B-1)//50
RA=(A-1)%50
RB=(B-1)%50

def PRINTw(x): #x個の白１黒３ブロック
    for j in range(x):
        print(".#",end="")
    for j in range(50-x):
        print("##",end="")
    print()
    for j in range(100):
        print("#",end="")
    print()
def PRINTb(x): #x個の白３黒１ブロック
    for j in range(100):
        print(".",end="")
    print()
    for j in range(x):
        print(".#",end="")
    for j in range(50-x):
        print("..",end="")
    print()

print("40 100")

for i in range(QA):
    PRINTw(50)
PRINTw(RA)
for i in range(10-(QA+1)):
    PRINTw(0)

for i in range(QB):
    PRINTb(50)
PRINTb(RB)
for i in range(10-(QB+1)):
    PRINTb(0)
