n=int(input())
s=input()
if n==8:
    print('vaporeon');quit()
elif n==6:
    print('espeon');quit()
a=[0,"jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"]
c1=0;c2=0;c3=0;c4=0;c5=0;c6=0
for x in zip(s,a[1]):
    if x[0]==x[1]:
        c1+=1
for x in zip(s,a[2]):
    if x[0]==x[1]:
        c2+=1
for x in zip(s,a[3]):
    if x[0]==x[1]:
        c3+=1
for x in zip(s,a[4]):
    if x[0]==x[1]:
        c4+=1 
for x in zip(s,a[5]):
    if x[0]==x[1]:
        c5+=1
for x in zip(s,a[6]):
    if x[0]==x[1]:
        c6+=1     
if c1>c2 and c1>c3 and c1>c4 and c1>c5 and c1>c6:
    print(a[1])
elif c2>c1 and c2>c3 and c2>c4 and c2>c5 and c2>c6:
    print(a[2])
elif c3>c2 and c1>c1 and c1>c4 and c1>c5 and c1>c6:
    print(a[3])
elif c4>c2 and c4>c3 and c4>c1 and c4>c5 and c4>c6:
    print(a[4])
elif c5>c2 and c5>c3 and c5>c4 and c5>c1 and c5>c6:
    print(a[5])
elif c6>c2 and c6>c3 and c6>c4 and c6>c5 and c6>c1:
    print(a[6])      