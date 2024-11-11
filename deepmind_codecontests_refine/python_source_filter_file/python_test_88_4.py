# cook your dish here
t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    l = len(a)
    flag = False
    if l%2==0:
        flag = True
    
    else:
        for j in range(l-1):
            if a[j]>a[j+1]:
                flag = True
                break
    
    if flag:
        print("YES")
    
    else:
        print("NO")