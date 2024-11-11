a,b,c,n=map(int ,input().split())
no=a+b-c
if no<=0 or c<b or c<a  :
    print("-1")
else:
    print(n-no)