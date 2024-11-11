
def __getType__(self):
    b=str(self)
    if b=='a' or b=='e' or b=='i' or b=='o' or b=='u':
        return 1
    else:
        return 0
a=str(input())
b=str(input())
len=a.__len__()
f=True
if len!=b.__len__():
    f=False
else:
    for i in range(len):
        aa=__getType__(a)
        bb=__getType__(b)
        if aa!=bb:
            f=False
            break
if f:
    print('Yes')
else:
    print('No')