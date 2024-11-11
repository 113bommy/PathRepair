n=int(input())
l=list(map(int,input().split()))
if(n%2!=0):
    print(l[n//2])
else:
    print(l[(n//2)-1])
