m,n,z = input().split()
m,n,z = int(m), int(n), int(z)
count = 0
for i in range(1, z//m):
    if (m*i)%n==0:
        count+=1
print(count)