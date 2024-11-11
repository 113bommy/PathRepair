n=int(input())
list1= list(map(int, input().split()))
a,b = map(int, input().split())
c=b-a
d=sum(list1[:c])
print(d)