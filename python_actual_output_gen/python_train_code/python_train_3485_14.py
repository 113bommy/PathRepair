t= int(input())
while t:
    t-=1
    #caa  ->ca   ->cba
    #cbb  ->cbab ->cba
    a = [0 for x in range(26)]
    n= int(input())
    for i in range(n):
        s = input()
        for e in s:
            a[ord(e)-ord('a')]+=1
    gg=False
    for e in a:
        if e%2!=0:
            gg=True
            break
    if gg:
        print("NO")
    else:
        print("YES")