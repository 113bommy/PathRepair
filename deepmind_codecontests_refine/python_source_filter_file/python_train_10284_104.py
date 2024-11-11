K=int(input())
a,b=map(int,input().split())
print("OK" if b-a+1/K>=1 else "NG")