a=int(input())
b=input()
b=b.split(' ')
b=[*map(int, b)]
if(len(b)>1):
    b=set(b)
    b=list(b)
    b.sort()
    if(len(b)>1):
        print(b[1])
    else:
        print(b[0])
else:
    print("NO")