def div3():
    div = []
    for i in range(1,1700):
        if (i%3!=0) and (i%10!=3):
            div.append(i)
    return div 

t = int(input())
div = div3()
for i in range(t):
    k = int(input())
    print('res: ',div[k-1])