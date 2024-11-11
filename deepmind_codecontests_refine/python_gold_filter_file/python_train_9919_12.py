q=int(input())
for i in range (q):
    b,a=map(int,input().split())
    if b==1 or b==2:
        print(1)
    else:
        b=b-3+a
        c=b//a + 1
        print(c)