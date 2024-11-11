n = int(input())

for i in range(n):
    l  = [int(p) for p in input().split(' ')]
    a = set([int(p) for p in input().split(' ')] )
    b = set([int(p) for p in input().split(' ')])
    
    
    intersection = a.intersection(b)
    
    if len(intersection) >0:
        print("YES")
        print(intersection.pop())
    else:
        print("NO")
    