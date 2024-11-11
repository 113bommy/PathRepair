d=int(input())
c=list(map(int,input().split()))
s=[list(map(int,input().split())) for _ in range(d)]

for i in range(365):
    print(i%26)