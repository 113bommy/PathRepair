l = list(map(int,input().split()))
l.sort()
if l[0]==l[1]==l[2]==l[3] or l[4]==l[1]==l[2]==l[3] or l[5]==l[4]==l[2]==l[3]:
    if l[0]==l[5] or (l[0]==l[1] and l[4]==l[5]):
        print("Elefant")
    else:
        print("Bear")
else:
    print("Alien")