line=str(input())
line.lower()
s=0
for ch in line:
    s=s+1
    if ch=="a":
        line=line[:s-1]+line[s:]
        s=s-1
    if ch=="o":
         line=line[:s-1]+line[s:]
         s=s-1
    if ch=="y":
         line=line[:s-1]+line[s:]
         s=s-1
    if ch=="e":
         line=line[:s-1]+line[s:]
         s=s-1
    if ch=="u":
         line=line[:s-1]+line[s:]
         s=s-1
    if ch=="i":
         line=line[:s-1]+line[s:]
         s=s-1
t="."
s=0
for ch in line:
    t=t+ch+"."
    s=s+1
t=t[:2*s]
print(t)
    

        
