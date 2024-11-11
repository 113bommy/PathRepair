n=int(input())
for i in range(n):
    s=str(input())
    if(s.startswith('miao.') and s.endswith('lala.')):
        print("OMG>.< I don't know!")
    elif(s.startswith('miao.')):
        print("Rainbow's")
    elif(s.endswith('lala.')):
        print("Freda's")
    else:
        print("OMG>.< I don't know!")