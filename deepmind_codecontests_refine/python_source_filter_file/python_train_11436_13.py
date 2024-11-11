n=int(input())
S=input()

L,R=0,0
l,r=0,0

for i in S:
    if "(":l +=1
    else:l -=1;L=min(L,l)

for i in S[::-1]:
    if ")":r +=1
    else:r -=1;R=min(R,r)

print("("*-L+S+")"*-R)