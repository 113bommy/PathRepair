def mod():
    n,m,k,s=list(map(int,input().split(" ")))
    if n+k>m+s:
        print("First")
    else:
        print("Second")

mod()
