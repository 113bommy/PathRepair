import sys
input=sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    time = 0
    integer = [i for i in range(1,n+1)]
    l = []
    
    for i in range(n//2,n):
        time += i**2
        integer[0],integer[i] = integer[i],integer[0]
        l.append((1,i+1))
    
    for i in range(1,n//2):
        time += (n-1-i)**2
        integer[-1],integer[i] = integer[i],integer[-1]
        l.append((i+1,n))
    
    l.reverse()
    
    print(time)
    print(*integer)
    print(len(l))
    for i in l:
        print(i[0],i[1])