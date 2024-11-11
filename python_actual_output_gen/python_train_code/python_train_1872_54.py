n=int(input())
l=sort(map(int,input().split()))
print(["No","Yes"][l[-1]>=sum(l)-l[-1]])