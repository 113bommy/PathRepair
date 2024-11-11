n,k = map(int, input().split())
l = [*map(int, input().split())]
if l.count(0) == n:
    print(0)
else:
    if l[k-1] == 0:
        print(n - l.count(0))
    else:
        flag = 0
        for i in range(k,n-1):
            if l[i] != l[i+1]:
                print(i+1)
                flag = 1
                break
        if flag == 0:
            print(n)
                
        
    
