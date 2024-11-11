for i in range(int(input())):
    s=input()
    c=0
    for i in s:
        if i=='X':
            c+=1
    if c==0:
        print(0)
    elif c==12:
        print("6 1x12 2x6 3x4 4x3 6x2 12x1")
    else:
        c,l=1,[1,0,0,0,0,0]
        if (s[0]=='X' and s[6]=='X' ) or (s[1]=='X' and s[7]=='X' ) or (s[2]=='X' and s[8]=='X' ) or (s[3]=='X' and s[9]=='X' ) or (s[4]=='X' and s[10]=='X' ) or (s[5]=='X' and s[11]=='X' ):
            l[1]=1
            c+=1
        if (s[0]=='X' and s[4]=='X' and s[8]=='X') or (s[1]=='X' and s[5]=='X' and s[9]=='X') or (s[2]=='X' and s[6]=='X' and s[10]=='X') or (s[3]=='X' and s[7]=='X' and s[11]=='X'):
            l[2]=1
            c+=1
        if (s[0]=='X' and s[3]=='X' and s[6]=='X' and s[9]=='X') or (s[1]=='X' and s[4]=='X' and s[7]=='X' and s[10]=='X') or (s[2]=='X' and s[5]=='X' and s[8]=='X' and s[11]=='X'):
            l[3]=1
            c+=1
        if (s[0]=='X' and s[2]=='X' and s[4]=='X' and s[6]=='X' and s[8]=='X' and s[10]=='X') or (s[1]=='X' and s[3]=='X' and s[5]=='X' and s[7]=='X' and s[9]=='X' and s[11]=='X'):
            l[4]=1
            c+=1
        print(c,"1*12",end=" ")
        if l[1]==1:
            print("2*6",end=" ")
        if l[2]==1:
            print("3*4",end=" ")
        if l[3]==1:
            print("4*3",end=" ")
        if l[4]==1:
            print("6*2",end=" ")
    print()
            
        