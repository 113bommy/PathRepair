n = input()
print("NO" if int(n)%sum(map(int,n)) else "Yes")