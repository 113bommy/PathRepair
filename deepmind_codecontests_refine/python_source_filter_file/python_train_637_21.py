n=input()
c=[int(i)%2 for i in input().split()].count
s=[int(i)%2 for i in input().split()].count
print(min(c(1),s(0))+min(c(0),c(1)))