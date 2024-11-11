t=int(input())
for i in range(t):
    s=input()
    if(s.endswith('lala.') and not s.startswith('miao.')):
        print("Freda's")
    elif(s.startswith('miao.') and not s.endswith('lala.')):
        print("Rainbow's")
    else:
        print("OMG>.< I don't know!")

