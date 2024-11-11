a,b,c=[int(i) for i in input().split()]
if c in [(a*i)%b for i in range(b)]:
    print("Yes")
else:
    print("No")