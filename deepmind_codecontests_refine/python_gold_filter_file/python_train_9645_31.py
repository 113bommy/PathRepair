a=int(input())
b=list(map(int,input().split()))
while b.count(0)!=0:
    b.remove(0)
b=set(b)
print(len(b))