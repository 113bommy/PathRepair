#rock pair scissor
f = input();
m = input();
s = input();
if f=='rock' and m=='scissor' and s=='scissor':
    print('F')
elif m=='rock' and f=='scissor' and s=='scissor':
    print('M')
elif s=='rock' and f=='scissor' and m=='scissor':
    print('S')
elif f=='scissor' and m=='paper' and s=='paper':
    print('F')
elif m=='scissor' and f=='paper' and s=='paper':
    print('M')
elif s=='scissor' and f=='paper' and m=='paper':
    print('S')
elif f=='paper' and m=='rock' and s=='rock':
    print('F')
elif m=='paper' and f=='rock' and s=='rock':
    print('M')
elif s=='paper' and f=='rock' and m=='rock':
    print('S') 
else:
    print('?')