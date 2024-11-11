lis1=["zero","one","two","three","four","five","six","seven","eight","nine"]
list2=["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
#list3=["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninrty"]
number=input()
y=int(number)
if len(number)==1:
    print(lis1[y])
else:
    if number[0]=='1':
        print(list2[int(number[1])])
    elif number[0]=='2':
        if number[1]=='0':
            print("twenty")
        else:
            print(f"twenty-{lis1[int(number[1])]}")
    elif number[0]=='3':
        if number[1]=='0':
            print("thirty")
        else:
            print(f"thirty-{lis1[int(number[1])]}")
    elif number[0]=='4':
        if number[1]=='0':
            print("fourty")
        else:
            print(f"fourty-{lis1[int(number[1])]}")
    elif number[0]=='5':
        if number[1]=='0':
            print("fifty")
        else:
            print(f"fifty-{lis1[int(number[1])]}")
    elif number[0]=='6':
        if number[1]=='0':
            print("sixty")
        else:
            print(f"sixty-{lis1[int(number[1])]}")
    elif number[0]=='7':
        if number[1]=='0':
            print("seventy")
        else:
            print(f"seventy-{lis1[int(number[1])]}")
    elif number[0]=='8':
        if number[1]=='0':
            print("eighty")
        else:
            print(f"eighty-{lis1[int(number[1])]}")
    elif number[0]=='9':
        if number[1]=='0':
            print("ninety")
        else:
            print(f"ninety-{lis1[int(number[1])]}")