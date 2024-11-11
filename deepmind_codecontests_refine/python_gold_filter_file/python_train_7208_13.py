from sys import stdin
t = int(stdin.readline())
#t = int(input())
for j in range(t):
#    n,m,k = [int(x) for x in input().split()]
    n,m,k = map(int,stdin.readline().split())
    each_get = n//k
    if each_get>=m:
        if m==0:
            print(0)
        else:
            print(m)
    else:
        left_joker = m-each_get
        if left_joker%(k-1)==0:
            print(each_get-(left_joker//(k-1)))
        else:
            if left_joker<(k-1):
                print(each_get-1)
            else:
                print(each_get-(left_joker//(k-1))-1)
        
    
    
    
