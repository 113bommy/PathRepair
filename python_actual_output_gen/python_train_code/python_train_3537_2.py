import sys
 
 
alph="abcdefghijklmnopqrstuvwxyz"
allis=list(alph)
S=input()
if(S=="zyxwvutsrqponmlkjihgfedcba"):
    print(-1)
    sys.exit()
 
for i in alph:
    if(i not in S):
        print(S)
        sys.exit()
        
l=-1
for i in range(len(S)-1)[::-1]:
    if(ord(S[i])<ord(S[i+1])):
        l=i
        break
        
x=sorted(S[i+1:])
for i in x:
    if(i>S[l]):
        print(S[:l]+i)
        sys.exit()