n = int(input())

for i in range(0,n,1234567):
    for j in range(0,n-i,123456):
        if (n-i-j) % 1234 == 0:
            print("YES")
            quit()
print("NO")