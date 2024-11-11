n=int(input())
ar=(list(map(int,input().split())))
ar1=(list(map(int,input().split())))
if sum(ar)<=sum(ar1):
    print("Yes")
else:
    print('No')