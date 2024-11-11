list_sep=[1998,2098,3098,13098,113098,1113098,11113098,111113098,1111113098]
def go(st):
    length=len(st)
    if length>=4:
        if int(st)<list_sep[length-2]:
            print('1'+st)
        else:
            print(st)
    else:
        if length==3:
            if int(st)<99:
                print('3'+st)
            else:
                print('2'+st)
        else:
            if length==2:
                if int(st)==99:
                    print('1999')
                else:
                    print('20'+st)
            else:
                if int(st)==9:
                    print('1989')
                else:
                    print('199'+st)

n=int(input())
for i in range(n):
    #print(input()[4:])
    go(input()[4:])
