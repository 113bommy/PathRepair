f=0;s=0
a=[input() for i in range(8)]
for i in range(8):
    for j in a[i]:
        if j== 'q': s+=9
        elif j=='r': s+=5
        elif j=='b': s+=3
        elif j=='n': s+=3
        elif j=='p': s+1
        if j== 'Q': f+=9
        elif j=='R': f+=5
        elif j=='B': f+=3
        elif j=='N': f+=3
        elif j=='P': f+1
if f==s: print("Draw")
elif f>s: print("White")
else: print("Black")