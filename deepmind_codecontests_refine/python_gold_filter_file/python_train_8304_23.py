H,N = map(int,input().split())
A = list(map(int,input().split()))

print(["No","Yes"][sum(A)>=H])