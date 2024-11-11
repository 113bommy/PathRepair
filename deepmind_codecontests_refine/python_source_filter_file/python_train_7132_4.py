SYMBOLS={'}':'{',']':'[',')':'(','>':'<'}
SYMBOLS_L,SYMBOLS_R=SYMBOLS.values(),SYMBOLS.keys()



arr=[]
num=0
left=0
right=0
flag=True
s=input()
for c in s:
    if c in SYMBOLS_L:
        arr.append(c)
        left+=1
    elif c in SYMBOLS_R:
        right+=1
        if len(arr) == 0:
            flag=False
            break
        elif arr[-1] == SYMBOLS[c]:
            arr.pop()
        else:
            num+=1
            arr.pop()

if right!=left:
    flag=False
if flag:
    print(num)
else:
    print('impossible')
