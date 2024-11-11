s=input()
x,y=s.count('4'),s.count('7')
if x==0 and y==0:
    print(-1)
else:
    if x>=y:
        print(4)
    else:
        print(7)