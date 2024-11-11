a = str(input())
b = str(input())
c = str(int(a) + int(b))
if int(a.replace('0', '')) + int(b.replace('0', '')) == int(c.replace('0', '')):
    print('yes')
else:
    print('no')