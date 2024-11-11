n=int(input())
a=sorted(map(int,input().split()))
print(sum(a[1::2])-sum(a[::2]))