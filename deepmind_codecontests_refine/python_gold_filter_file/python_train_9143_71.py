a,b,c,d=map(int,input().split())
print(max(0,min(b-c,d-a,b-a,d-c)))