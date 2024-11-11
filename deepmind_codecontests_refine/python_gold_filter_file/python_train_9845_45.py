n = int(input())
s = input()
m = sum(a in 'A' for a in s)
print(['Friendship','Anton','Danik'][(m>(n-m)) - (m<(n-m))])