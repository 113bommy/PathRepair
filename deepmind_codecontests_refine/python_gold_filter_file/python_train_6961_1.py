import sys
line=[]
in_line=sys.stdin
for _in in in_line:line.append(_in)
#for i in range(89):line.append(input())
sets=(len(line)+1)//9
for i in range(sets):
    flag=0
    topindex=-1
    for j in range(i*9,i*9+9):
        a=line[j].count('1')
        if a!=0:t=line[j].index('1')
        else:t=-1
        if a==4:
            print('C')
            break
        elif flag==0 and a!=0:
            topindex=t
            if a==1:flag=1
            elif a==2:flag=2
        elif flag==1:
            if a==1:
                print('B')
                break
            elif a==2:
                if topindex==t:
                    print('F')
                    break
                else:
                    print('D')
                    break
        elif flag==2:
            if topindex==t:
                print('A')
                break
            elif topindex<t:
                print('E')
                break
            else:
                print('G')
                break