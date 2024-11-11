N=int(input())
A=list(map(int,input().split()))
a=1
for i in A:
    a^=i
print(["No","Yes"][a==1])