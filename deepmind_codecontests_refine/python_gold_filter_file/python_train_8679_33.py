n = int(input())
a = [int(x) for x in input().split()]
dic = {}
if n==1 and a[0]==1:
    print(a[0]+1)
elif n==1 :
    print(1)
else:
    for i in a :
        dic[i] = 1
    for i in range(1,n+2):
        if i not in dic:
            print(i)
            break
