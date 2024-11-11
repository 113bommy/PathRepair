n = int(input())

n = n-10

dict = {1:4,2:4,3:4,5:4,6:4,7:4,8:4,9:4,10:15,11:4}

if n<=0:
    print(0)
else:
    if n in dict:
        print(dict[n])
    else:
        print(0)


