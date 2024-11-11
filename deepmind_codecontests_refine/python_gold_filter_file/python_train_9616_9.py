m = int(input())
l = list(map(int,input().split()))
l = list(map(lambda x: x%2,l))

if l[0] != l[1]:
    if l[0] == l[2]:
        print(2)
    else:
        print(1)
else:
    for i in range(1,m):
        if l[i] != l[0]:
            k = i+1
            print(k)
            break
