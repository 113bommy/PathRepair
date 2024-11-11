list3=['aab', 'd.b', 'dcc']
list4=['aacd', 'bbcd', 'efgg', 'efhh']
list5=['abc..', 'abc..', 'ddehh', 'g.eii', 'gffjj']
list7=['.aabbcc', 'dghh...', 'dg.j...', 'eiij...', 'e...kll', 'f...k.n', 'f...mmn']

n=int(input())
if n<=2:
    print(-1)
if n%3==0:
    lists=[]
    for i in range(n):
        row='.'*((i//3)*3)+list3[i%3]+'.'*(n-3-(i//3)*3)
        lists.append(row)
    for l in lists:
        print(l)
else:
    kotae=[
            [],
            [],
            [],
            [],
            [1,0,0],
            
            [0,1,0],
            [],
            [0,0,1],
            [2,0,0],
            [1,1,0],
            
            [0,2,0],
            [1,0,1],
            [3,0,0],
            [2,1,0],
            [1,2,0],
            
            [0,3,0],
            [4,0,0],
            [3,1,0],
            [2,2,0],
            [1,3,0],
            
            [0,4,0],
            [4,1,0],
            [3,2,0],
            [2,3,0],
            [6,0,0],
            
            [0,5,0],
            [4,2,0]
        ]
    if n<=25:
        loop=kotae[n]
    else:
        mazu=n%20
        if mazu<7:
            mazu+=20
        loop=kotae[mazu]
        loop[0]+=((n-mazu)//20)*5
    
    lists=[]
    now=0
    for i in range(loop[0]*4):
        row='.'*(i//4)*4+list4[i%4]+'.'*(n-4-(i//4)*4)
        lists.append(row)
    now+=loop[0]*4
    
    for i in range(loop[1]*5):
        row='.'*(now+(i//5)*5)+list5[i%5]+'.'*(n-5-now-(i//5)*5)
        lists.append(row)
    now+=loop[1]*5
    
    for i in range(loop[2]*7):
        row='.'*(now+(i//7)*7)+list7[i%7]+'.'*(n-7-now-(i//7)*7)
        lists.append(row)
    now+=loop[1]*7
    
    for l in lists:
        print(l)