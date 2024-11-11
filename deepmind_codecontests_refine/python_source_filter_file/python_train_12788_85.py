A,B,C,D,E,F = map(int,input().split())

W = set()
for i in range(0,F+1,100*A):
    for j in range(0,F+1-i,100*B):
        W.add(i+j)
        
S = set()
for i in range(0,F+1,C):
    for j in range(0,F+1-i,D):
        S.add(i+j)

rate = 0
for w in W:
    for s in S:
        if 0 < w+s <= F and s/(w+s) <= E/(E+100):
            if s/(w+s) > rate:
                rate= s/(w+s)
                res1,res2 = w+s,s
                
print(res1,res2)