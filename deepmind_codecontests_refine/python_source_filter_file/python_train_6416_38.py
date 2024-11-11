a=int(input())
if (a%10<5):
    print(a-a%10)
elif (a%10>=5):
    print(a+(10-a))
