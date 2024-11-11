a=input()
c=0
b=list(a)
for i in range (1,len(a)):
    if b[i]=='a' or b[i]=='b' or b[i]=='c' or b[i]=='d' or b[i]=='e' or b[i]=='f' or b[i]=='g' or b[i]=='h' or b[i]=='i' or b[i]=='j' or b[i]=='k' or b[i]=='l' or b[i]=='m' or b[i]=='n' or b[i]=='o' or b[i]=='p' or b[i]=='q' or b[i]=='r' or b[i]=='s' or b[i]=='t' or b[i]=='u' or b[i]=='v' or b[i]=='w' or b[i]=='x' or b[i]=='y' or b[i]=='z':
        c=1
if c==1:
    print(a)
else:
    d=a.capitalize()
    print(d)
