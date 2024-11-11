t = int(input())

while(t):
    s = input()
    zer = s.count('0')
    one = s.count('1')
    if(one == 0):
        print('0'*len(s))
    elif(zer==0):
        print('1'*len(s))
    else:
        print('01'*(len(s)-1))
    t-=1