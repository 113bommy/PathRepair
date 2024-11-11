n = int(input())

a = [int(x)%2 for x in input().split()]
if sum(a)>0:
    print("FIRST")
else:
    print("SECOND")
