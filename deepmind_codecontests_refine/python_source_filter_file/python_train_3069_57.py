d={ 'q':9, 'r':5, 'b':3, 'n':3, 'p':1, 'k':0, 'Q':9, 'R':5, 'B':3, 'N':3, 'P':1, 'K':0}
s=''
for i in range(8):
    s=s+input()
s=s.replace('.','')
W=0
B=0
for i in s:
    if i.isupper():
        W=W+d[i]
    elif i.islower():
        B=B+d[i]
print(s)
if B>W:
    print('Black')
elif B<W:
    print('White')
else:
    print('Draw')
