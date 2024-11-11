test = int(input())
for num in range(test):
    n = int(input())
    temp = ""
    hudai = ""
    a,b,c = map(int,(input().split()))
    senten = input()
    l = len(senten)
    for i in range(l):
        if senten[i] == 'R' :
            if(b>0):
                temp += 'P'
                b -= 1
            else :
                temp += '!'
        elif senten[i] == 'P' :
            if(c>0):
                temp += 'S'
                c -= 1
            else :
                temp += '!'
        elif senten[i] == 'S' :
            if(a>0):
                temp += 'R'
                a -= 1
            else :
                temp += '!'
    wait_bro = (n+1)/2
    if(n-a-b-c<wait_bro):
        print("NO")
    else:
        print("YES")
        for laga in range(l) :
            if temp[laga] != '!':
                hudai += temp[laga]
            else:
                if a>0:
                    hudai += 'R'
                    a -= 1
                elif b>0:
                    hudai += 'P'
                    b -= 1
                else :
                    hudai += 'S'
        print(hudai)





