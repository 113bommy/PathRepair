s=input()
l=input()
d=input()
counta=0
countb=0
countc=0
if s[0]=='A' and s[1]=='>' and s[2]=='B':
    counta+=1
if s[0]=='A' and s[1]=='>' and s[2]=='C':
    counta+=1
if s[0]=='A' and s[1]=='<' and s[2]=='B':
    countb+=1
if s[0]=='A' and s[1]=='<' and s[2]=='C':
    countc+=1
if s[0]=='B' and s[1]=='>' and s[2]=='A':
    countb+=1
if s[0]=='B' and s[1]=='>' and s[2]=='C':
    countb+=1
if s[0]=='B' and s[1]=='<' and s[2]=='A':
    countb+=1
if s[0]=='B' and s[1]=='<' and s[2]=='C':
    countc+=1
if s[0]=='C' and s[1]=='>' and s[2]=='B':
    countc+=1
if s[0]=='C' and s[1]=='>' and s[2]=='A':
    countc+=1
if s[0]=='C' and s[1]=='<' and s[2]=='B':
    countb+=1
if s[0]=='C' and s[1]=='<' and s[2]=='A':
    counta+=1 
if l[0]=='A' and l[1]=='>' and l[2]=='B':
    counta+=1
if l[0]=='A' and l[1]=='>' and l[2]=='C':
    counta+=1
if l[0]=='A' and l[1]=='<' and l[2]=='B':
    countb+=1
if l[0]=='A' and l[1]=='<' and l[2]=='C':
    countc+=1
if l[0]=='B' and l[1]=='>' and l[2]=='A':
    countb+=1
if l[0]=='B' and l[1]=='>' and l[2]=='C':
    countb+=1
if l[0]=='B' and l[1]=='<' and l[2]=='A':
    countb+=1
if l[0]=='B' and l[1]=='<' and l[2]=='C':
    countc+=1
if l[0]=='C' and l[1]=='>' and l[2]=='B':
    countc+=1
if l[0]=='C' and l[1]=='>' and l[2]=='A':
    countc+=1
if l[0]=='C' and l[1]=='<' and l[2]=='B':
    countb+=1
if l[0]=='C' and l[1]=='<' and l[2]=='A':
    counta+=1    
if d[0]=='A' and d[1]=='>' and d[2]=='B':
    counta+=1
if d[0]=='A' and d[1]=='>' and d[2]=='C':
    counta+=1
if d[0]=='A' and d[1]=='<' and d[2]=='B':
    countb+=1
if d[0]=='A' and d[1]=='<' and d[2]=='C':
    countc+=1
if d[0]=='B' and d[1]=='>' and d[2]=='A':
    countb+=1
if d[0]=='B' and d[1]=='>' and d[2]=='C':
    countb+=1
if d[0]=='B' and d[1]=='<' and d[2]=='A':
    countb+=1
if d[0]=='B' and d[1]=='<' and d[2]=='C':
    countc+=1
if d[0]=='C' and d[1]=='>' and d[2]=='B':
    countc+=1
if d[0]=='C' and d[1]=='>' and d[2]=='A':
    countc+=1
if d[0]=='C' and d[1]=='<' and d[2]=='B':
    countb+=1
if d[0]=='C' and d[1]=='<' and d[2]=='A':
    counta+=1   
#print(counta,countb,countc)    
if counta!=2 and countb!=2 and countc!=2:
    print("Impossible")
else:
    if counta==2 and countb==1 and countc==0:
        print("CBA")
    if counta==2  and countc==1 and countb==0:
        print("BCA")
    if countb==2 and counta==0 and countc==1:
        print("ACB")
    if counta==1 and countc==0 and countb==2:
        print("CAB")
    if countc==2 and countb==1 and counta==0:
        print("ABC")
    if countc==2  and counta==1 and countb==0:
        print("BAC")    
    
