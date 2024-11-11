k=int(input())
a,b=map(int,input().split())
print("NG" if (a-1)//k==(b-1)//k else"OK")