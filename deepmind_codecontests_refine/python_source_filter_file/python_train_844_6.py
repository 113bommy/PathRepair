n=int(input())
a=['a','b','c','d']
for i in range(n):
    x=i%(n-1)
    print(a[x],end="")
