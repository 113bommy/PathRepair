n=int(input())
list1=list(sorted(list(map(int,input().split()))))
print(list1[-1]-list1[0]-n)