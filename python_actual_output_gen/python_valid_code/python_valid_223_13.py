n = int(input())
z = 'No'
for i in range(1,(n//4)+1):
    if (n-4*i)%7 == 0:
        z = 'Yes'
        break
print(z)