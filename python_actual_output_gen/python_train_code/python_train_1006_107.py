for i in range(int(input())):
    s = input()
    if len (s) <= 10:
        print (s)
    else:
        print(str(s[0])+str(len(s))+str(s[-1]))