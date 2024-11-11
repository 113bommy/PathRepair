t = int(input())
for i in range (t) :
    ans = 0
    i=0
    lst = input()
    # if lst[0]==0 :
    #     lst = '1'+lst
    #     i=1
    lst = lst.split('0')
    
    lst2=[]
    for item in lst :
        lst2.append(len(item))

    lst2.sort()
    lst2.reverse()

    while (i<len(lst2)) :
        ans = ans + lst2[i]
        i+=2

print(ans)