c = int(input())
li=[1,2,3,4,5,6,7,8,9,11]
if c<=10:
    print(0)
else:
    diff= c-10
    if diff>11:
        print(0)
    elif diff in li:
        print(4)
    else:
        print(15)