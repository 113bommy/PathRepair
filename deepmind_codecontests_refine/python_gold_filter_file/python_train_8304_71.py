h,n = map(int,input().split())
a = list(map(int,input().split()))
print(["No","Yes"][sum(a) >= h])