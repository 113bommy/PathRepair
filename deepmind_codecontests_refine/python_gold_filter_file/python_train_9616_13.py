n = int(input())
v = list(map(int,input().strip().split()))
for i in range(n):
    if(v[i]%2!=v[(i-1)%n]%2 and v[i]%2!=v[(i+1)%n]%2):
        p = i
        break;
print(p+1)