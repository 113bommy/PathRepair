t=int(input())
for _ in range(t):
    a,b,l=map(int,input().split())
    count=0
    while a<l and b<l:
        if a<b:
            b+=a
        else:
            a+=b
        count+=1
    print(count)
            