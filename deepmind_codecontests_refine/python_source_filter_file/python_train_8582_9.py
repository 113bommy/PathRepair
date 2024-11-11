n=int(input())
s=['vaporeon']
s1=['jolteon', 'flareon', 'umbreon', 'leafeon', 'glaceon' , 'sylveon']
s2=[ 'espeon']
st=input()
if n==8:
    print(s[0])
elif n==6:
    print(s2[0])
else:
    for i in s:
        f=True
        kr=0
        for j in range(n):
            if st[j]!='.':
                kr+=1
                try:
                    if st[j]!=i[j]:
                        f=False
                except:
                    f=False
        if f:
            print(i)
            break
                    