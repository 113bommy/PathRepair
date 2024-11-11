r,b = map(int,input().split())
if r>b:
    print(b,((r-b)//2))
if r<b:
    print(r,((b-r)//2))
if r==b:
    print(r,0)
