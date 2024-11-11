t=int(input())
finalans = []
for _ in range(t):
    n=input()
    list1=[1,11,111,1111]
    list2=[2,22,222,2222]
    list3=[3,33,333,3333]
    list4=[4,44,444,4444]
    list5=[5,55,555,5555]
    list6=[6,66,666,6666]
    list7=[7,77,777,7777]
    list8=[8,88,888,8888]
    list9=[9,99,999,9999]
    ans=[]

    def countDigit(n):
        count = 0
        while n != 0:
            n //= 10
            count+= 1
        return count

    if n[0]=='1':
        for i in list1:
            if i<=int(n):
                ans.append(i)
    if n[0]=='2':
        ans+=list1
        for i in list2:
            if i<=int(n):
                ans.append(i)
    if n[0]=='3':
        ans+=list1+list2
        for i in list3:
            if i<=int(n):
                ans.append(i)
    if n[0]=='4':
        ans += list1 + list2+list3
        for i in list4:
            if i<=int(n):
                ans.append(i)
    if n[0]=='5':
        ans += list1 + list2+list3+list4
        for i in list5:
            if i<=int(n):
                ans.append(i)
    if n[0]=='6':
        ans += list1 + list2 + list3 + list4+list5
        for i in list6:
            if i<=int(n):
                ans.append(i)
    if n[0]=='7':
        ans += list1 + list2 + list3 + list4+list5+list6
        for i in list7:
            if i<=int(n):
                ans.append(i)
    if n[0]=='8':
        ans += list1 + list2 + list3 + list4+list5+list6+list7
        for i in list8:
            if i<=int(n):
                ans.append(i)
    if n[0]=='9':
        ans += list1 + list2 + list3 + list4 + list5 + list6 + list7+list8
        for i in list9:
            if i<=int(n):
                ans.append(i)

    counterans=0
    for i in ans:
        counterans+=countDigit(i)

    finalans.append(counterans)

for i in finalans:
    print(i)