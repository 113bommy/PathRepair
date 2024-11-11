n= int(input())
if n%10==0:
    print(n)
elif n%10==5:
    print(n+5)
elif n%10<=4:
    print(n-(n%5))
elif n%10>5:
    print(n+(5-n%5))