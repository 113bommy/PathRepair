a,b,c,d = map(int,input().split())
print(max(0,min(b-a,b-c,d-c,d-a)))