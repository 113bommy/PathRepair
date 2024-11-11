n=int(input())
l=list(map(int,input().split()))
s=0
for i in l:
    s+= i/100
print(round(s/n,12))