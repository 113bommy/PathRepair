n=input()
n=n[::-1]
s="O-|-OOOO"
def less(p):
    print("O"*p+"-"+"O"*(4-p))
for i in range(len(n)):
    q=int(n[i])
    if(q>5):
        print("-O|",end="")
        less(q-5)
    elif(q>0 and q<5):
        print("O-|",end="")
        less(q)
    else:
        print(s)
    
    
    
    