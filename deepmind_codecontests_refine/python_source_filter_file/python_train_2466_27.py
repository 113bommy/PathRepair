a=int(input())
b=list(map(int,input().split()))
b.sort()
print (b[len(b)//2])
