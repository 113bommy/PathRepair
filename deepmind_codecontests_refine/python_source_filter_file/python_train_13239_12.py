s = input()
if s=='0':
    print(0)
elif int(s)/(10**(len(s)-1))==1.0:
    print((len(s)//2))
elif len(s)%2==0:
    print(len(s)//2)
else:
    print((len(s)//2)+1)    