import sys

S=input()
k=int(input())

qu=S.count("?")
ast=S.count("*")
L=len(S)

if k<L-2*qu-2*ast:
    print("Impossible")
    sys.exit()

if ast==0 and k>L-qu:
    print("Impossible")
    sys.exit()

ANS=""
NOW=L-qu-ast

i=0
while i<len(S):
    if S[i]=="?":
        if  NOW>k:
            S=S[:i-1]+S[i+1:]
            NOW-=1
        else:
            S=S[:i]+S[i+1:]

        i=i-1
        continue

    if S[i]=="*":
        if NOW<k:
            S=S[:i]+S[i-1]*(k-NOW)+S[i+1:]
            NOW=k
        elif  NOW>k:
            S=S[:i-1]+S[i+1:]
            NOW-=1
        else:
            S=S[:i]+S[i+1:]

        i=i-1
        continue
    i+=1
    #print(i,S,NOW,k)

print(S)
        
        
    
