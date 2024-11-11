import sys
n = 0; s=0
for i in sys.stdin:
    if i[0] == '+':
        n+=1
    elif i[0] == '-':
        n-=1
    else:
        s = s + n*len((i.split(':')[1]))
print(s)