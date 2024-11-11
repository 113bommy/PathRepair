f=input()
m=input()
s=input()
if f=='rock' and m=='scissors' and s=='scissors':
    print('F')
elif f=='paper' and m=='rock' and s=='rock':
    print('F')
elif f=='scissors' and m=='paper' and s=='paper':
    print('F')
elif f=='scissors' and m=='rock' and s=='scissors':
    print('M')
elif f=='scissors' and m=='scissors' and s=='paper':
    print('M')
elif f=='rock' and m=='paper' and s=='rock':
    print('M')
elif f=='scissors' and m=='scissors' and s=='rock':
    print('S')
elif f=='rock' and m=='rock' and s=='paper':
    print('S')
elif f=='paper' and m=='paper' and s=='scissors':
    print('S')
else:
    print('?')
