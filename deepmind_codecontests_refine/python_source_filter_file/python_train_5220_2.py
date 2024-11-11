from collections import Counter
import sys

S=input()
L=len(S)

def pand(x):
    if x==x[::-1]:
        return True
    else:
        return False

for i in range(1,len(S)):
    if S[i:]+S[:i]!=S and pand(S[i:]+S[:i])==True:
        print(1)
        sys.exit()


if len(Counter(S).keys())==1:
    print("Impossible")
    sys.exit()

if L%2==0:
    print(2)

else:
    for i in range(1,L//2):
        if S[:i]!=S[-i:]:
            print(2)
            sys.exit()
    else:
        print("Impossible")

    
