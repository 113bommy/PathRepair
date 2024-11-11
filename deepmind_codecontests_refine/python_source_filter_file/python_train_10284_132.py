k=int(input())
a,b=map(int,input().split())
r=b-a+1
if r>=k:
    print("OK")
else:
    print("NG")