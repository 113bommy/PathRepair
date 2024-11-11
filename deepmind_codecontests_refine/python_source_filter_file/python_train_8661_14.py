n=int(input())
while(n):
    n-=1
    num=input()
    if "0" in num:
        item=0
        flag=0
        for element in num:
            item+=int(element)
            if int(element)%2==0 and int(element)!=0 or num.count('0')>=1:
                flag=1
        if item%3==0 and flag==1 or item==0 :
            print("red")
        else:
            print("cyan")
    else:
        print("cyan")

