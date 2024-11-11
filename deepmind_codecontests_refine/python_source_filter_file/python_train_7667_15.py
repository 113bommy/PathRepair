n=int(input())
s=input().split()
x=len(set(([''.join((set(i))) for i in s])))
print(x)
