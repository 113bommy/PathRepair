n=int(input())
for i in range(n):
    if(i%2==0):
        if(i>0):
            print('that I hate',end=' ')
        else:
            print('I hate',end=' ')
    else:
        print('that I love',end=' ')
print('It')