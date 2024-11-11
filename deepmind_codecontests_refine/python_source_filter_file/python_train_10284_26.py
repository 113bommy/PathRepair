k=int(input())
a,b=map(int,input().split())

if b-k>=a-k>=k:
    print("OK")
else:
    print("NG")
