for _ in range(int(input())):
    n=int(input())
    if n==1:
        print(0)
        continue
    c=0
    while n%3==0:
        c+=1
        n//=3
    c2=0
    while n%2==0:
        c2+=1
        n//=2
    if n==1 and c>=c2:
        print(c+(c-2))
    else:
        print(-1)