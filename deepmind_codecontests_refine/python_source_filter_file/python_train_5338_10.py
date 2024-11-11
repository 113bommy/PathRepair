n = int(input())
b = list(map(int,input().split()))
b.sort(reverse = True)
a = [0]*(n+1)
j = 0
if n%2==0:
    for i in b[:n//2]:
        a[j] = i
        j+=2
    j = 1
        #print(a)
    for i in b[n//2:]:
        a[j] = i
        j+=2
    print(n//2-1)
    print(*a[:n],sep = ' ')
else:
    for i in b[:n//2+1]:
        a[j] = i
        j+=2
    j = 1
    print(a)
    for i in b[n//2+1:]:
        a[j] = i
        j+=2
    print(n//2)
    print(*a[:n],sep = ' ')
