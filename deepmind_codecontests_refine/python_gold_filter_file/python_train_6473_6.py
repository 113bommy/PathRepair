a=int(input())
b=sum(int(j)%2 for j in input().split())
print(min(b,a-b))