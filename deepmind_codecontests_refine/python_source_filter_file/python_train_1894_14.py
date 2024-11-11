n = int(input())
for i in range(n):
    m = int(input())
    lst = [int(x) for x in input().split()]
    lst2= [2,4,8,16,32,64,128,256,512,1024]
    lst3 = []
    if 2048 in lst:
        print("YES")
    else:
        for j in range(10):
            lst3.append(int(lst.count(lst2[j])))
            a=lst3[0]
        for k in range(1,10):
            a = a//2+lst3[k]
        if a >= 2:
            print("YES")
        else:
            print("NO")
        
