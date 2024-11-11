n=int(input())
l=list(map(int,input().split()))
l.sort()
x=l[-1]-l[0]
print(x-n)