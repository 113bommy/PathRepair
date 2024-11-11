N=int(input())
S=input()
b=0
h=S.count(".")
m=h
for i in range (len(S)):
    if(S[i]=="#"):
        b+=1
    else:
        h-=1
    if(m>max(b,h)):
        m=max(b,h)
print(m)