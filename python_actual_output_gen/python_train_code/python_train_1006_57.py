n=int(input())
for i in range(0,n,1):
    x=input()
    t=x.__len__()
    if(t<10):
        print(x)
    else:
        print(x[0]+str(t-2)+x[-1])
    print('\n')
