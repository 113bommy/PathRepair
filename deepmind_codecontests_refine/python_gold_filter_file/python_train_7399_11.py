while True:
    x=input()
    if "?" in x:
        break
    print(int(eval(x.replace("/","//"))))