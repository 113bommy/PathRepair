n,d=(int(i) for i in input().split())
l=[int(i) for i in input().split()]
m=int(input())
print(sum(l[:min(m,n)])-max(0,(m-n)*d))