n=int(input())
a=["aeiou","eioua","iouae","ouaei","uaeio"]
i=5
d=['a','e','i','o','u']
while 1:
    if n%i==0:
        m=n//i
        if n//i>=5:
            for b in range(m):
                s=a[b%5]
                print(a[b%5]*(m//5)+s[:m%5],end="")
            exit()
    i+=1
    if i>=100:
        print(-1)
        exit()
