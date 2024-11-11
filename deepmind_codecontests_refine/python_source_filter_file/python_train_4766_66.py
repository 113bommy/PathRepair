X,Y = [int(i) for i in input().split()]

print ("Yes" if Y%2 == 0 and Y//4 <= X <= Y//2 else "No")
