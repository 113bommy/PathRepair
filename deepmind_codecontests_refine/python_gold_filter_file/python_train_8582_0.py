n=int(input())
s=input()
if n==6:
    print("espeon")
elif n==8:
    print("vaporeon")
else:
    l=["jolteon", "flareon","umbreon","leafeon","glaceon","sylveon"]
    for i in range(6):
        z=0
        for j in range(7):
            if s[j]!='.' and s[j]!=l[i][j]:
                z=-1
                break
        if z==0:
            print(l[i])
        
        

