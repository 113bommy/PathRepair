

t=[ord('Q'),ord('R'),ord('B'),ord('N'),ord('P'), ord('q'), ord('r'), ord('b')
   , ord('n'), ord('p')]
s=[9,5,3,3,1,9,5,3,3,1]

blck=0
wht=0

for k in range(8):
    a=input()

    for i in range(8):
        if ord(a[i]) in t:
            if 97<= ord(a[i])<=122:
                blck+=s[t.index(ord(a[i]))]
            elif 65<=ord(a[i])<= 90:
                wht+=s[t.index(ord(a[i]))]
                


if blck > wht:
    print('Black')
elif wht < blck:
    print('White')
else:
    print('Draw')

    
