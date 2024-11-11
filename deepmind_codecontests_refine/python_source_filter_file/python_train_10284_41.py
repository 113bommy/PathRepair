k=int(input())
a,b=map(int,input().split())
if a%k <= b-a:
    print("OK")
else:
    print("NG")