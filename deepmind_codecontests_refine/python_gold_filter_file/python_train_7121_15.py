n=int(input())
arr=list(map(int,input().split()))
if(arr.count(0)>0):
    res='5'*(arr.count(5)-arr.count(5)%9)+'0'*arr.count(0)
    print(int(res))
else:
    print("-1")