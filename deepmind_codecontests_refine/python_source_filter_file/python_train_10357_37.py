n=input()
s=["zero","-one","-two","-three","-four","-five","-six","-seven","-eight","-nine"]
if len(n)<=1:
    print(s[int(n)][1:])
elif 10<=int(n)<=19:
    print(["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"][int(n)-10])
else:
    base=["","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]
    s[0]=""
    print(base[int(n[0])]+s[int(n[1])])
