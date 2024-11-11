for _ in range(int(input())):
    s=input()
    if len(set(s))==1:
        print(s)
    else:
        print('01'*4)
