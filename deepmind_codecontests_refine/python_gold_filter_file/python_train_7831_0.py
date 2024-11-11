for i in range(int(input())):
    t=input()
    if len(set(t))==1:
        print(t)
    else:
        print('01'*len(t))