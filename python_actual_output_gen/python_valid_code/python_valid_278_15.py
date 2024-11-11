n=int(input())
l=list(map(int,input().split()))
l.sort()
print(min(l[n-1]-l[0],l[n-2]-l[1]))
