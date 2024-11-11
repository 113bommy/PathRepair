a,b=map(int,input().split())
lft=b-1
rgt=a-b
if lft==rgt:
        print(b+1)
else:
        if lft>rgt:
                print(b-1)
        else:
                print(b+1)