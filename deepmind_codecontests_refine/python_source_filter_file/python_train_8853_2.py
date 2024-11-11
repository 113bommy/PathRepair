W=input()
T=[]
while 1:
 a=input()
 if'END_OF_TEXT '==a:break
 T+=[s.lower() for s in a.split()]
print(T.count(W))