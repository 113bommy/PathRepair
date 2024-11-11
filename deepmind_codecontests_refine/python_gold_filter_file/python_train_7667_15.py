n=int(input())
s=input().split()
x=len(set(([''.join(sorted(set(i))) for i in s])))
print(x)
