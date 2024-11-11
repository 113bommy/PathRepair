s=0
n=0
while True:
    try:
        a,b,c = map(int, input().split())
    except:
        break

    if a == b:
        n+=1
    elif c**2 == a**2 + b**2:
        s+=1

    print(str(s) + "\n" + str(n))