a,b=map(int,input().split())
i=1
win=""
while a>=0 and b>=0:
    if i%2==1:
        if a-i<0:
            win="a"
            break
        a=a-i;
    else:
        if b-i<0:
            win="b"
        b=b-i;
    i+=1
##    print(a,b)
if win=="a":
    print("Vladik")
else:
    print("Valera")
