hp, N=input().split()
a=input().split()
print("Yes") if sum([int(x) for x in a]) >= int(hp) else print("No")