from collections import Counter, OrderedDict
for _ in range(int(input())):

    n=int(input())


    arr=list(map(int,input().split()))

    dict_1=Counter(arr)

    dict_1=dict(OrderedDict(sorted(dict_1.items())))
    #print(dict_1)
    arr_1=[]
    print("yes")
    while max(dict_1.values())!=0:  
        #print(dict_1)
        for i in dict_1.keys():
            if dict_1[i]!=0:
                arr_1.append(i)
                dict_1[i]-=1

    print(" ".join(map(str,arr_1)))

