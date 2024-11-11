units =["zero","one","two","three","four","five","six","seven","eight","nine"]
tens = ["","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"]
cooked = ["","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
n = input()

if len(n)==1:
    print(units[int(n)])
else:
    if n[1]=="0":
        print(tens[int(n[0])])
    else:
        if n[0]=="1":
            print(cooked[int(n[1])])
        else:
            print(tens[int(n[0])]+"-"+units[int(n[1])])



