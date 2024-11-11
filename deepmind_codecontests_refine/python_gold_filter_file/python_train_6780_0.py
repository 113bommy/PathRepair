ch = input()
n = int(input())
snowflake,candy = [],[]
for i in range(0,len(ch)):
    if '*'==ch[i]:
        snowflake.append(i-1)
    elif ch[i]=='?':
        candy.append(i-1)

def add(ch,pos,how_much):
    return  ch[:pos+1] + ch[pos] * (
        how_much) + ch[pos + 1:]


def truncate(ch,index):
    new = ''
    for i in range(0,len(ch)):
        if i not in index:
            new = new+ch[i]
    return new
   

def clearify(ch):
    new =''
    for i in ch:
        if i.isalpha():
            new  = new+i
    return new

s,c = len(snowflake),len(candy)
item = n -(len(ch)-(s+c))
if item>0:
    if len(snowflake) ==0:
        print('Impossible')
        exit(0)
    else:
        ch = add(ch,snowflake[0],item)
elif item<0:
    need = abs(item)-(s+c)
    snowflake.extend(candy)
    if need>0:
        print('Impossible')
        exit(0)
    else:
        ch = truncate(ch,snowflake[:need] if need!=0 else snowflake )
ch = clearify(ch)
print(ch)



