n = int(input())
z = list(input().split())
q = int(z[0])
for i in range(1,n):
    q=q+abs(int(z[i])-int(z[i-1]))
print(q)