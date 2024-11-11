t = int(input())

for _ in range(t):
    n,a,b = map(int,input().split())
    s = input()
    if b>=0:
        print(a*n+b*n)
        continue
    v = list( ord(i) for i in s)
    tot = 0
    for i in range(1,n):
        if v[i]!=v[i-1]:tot+=1
    
    print((tot//2 + 1)* b + n * a)