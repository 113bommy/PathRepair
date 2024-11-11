S=input()
l=[]
n=int(input())
for i in range(n) :
    l.append(input())
if S in l or S[::-1] in l  :
    print('YES')
    exit()
for i in range(n) :
    if l[i][1]==S[1] :
        for j in range(n) :
            if l[j][0]==S[1] :
                print('YES')
                exit()
print('NO')
    
