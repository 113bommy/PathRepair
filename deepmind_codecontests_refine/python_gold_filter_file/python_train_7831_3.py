for _ in range(int(input())):
    a=input()
    if len(set(a))==1:
        print(a)
    else:
        print('01'*len(a))