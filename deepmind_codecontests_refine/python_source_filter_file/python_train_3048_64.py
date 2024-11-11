t=int(input())

def bits(x):
    s=""
    while x!=0:
        s+=str(x%2)
        x//=2
    s+="0"*(24-len(s))
    return s

for _ in range(t):
    a,b=map(int,input().split())
    a1=bits(a)
    b1=bits(b)
    e=0
    for i in range(24):
        if a1[i]!=b1[i]:
            e+=2**i
    print(e)