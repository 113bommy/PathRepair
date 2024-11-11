
s=int(input())
print("Yes" if any([str(i)*3 in str(s) for i in range(10)]) else "No" )
