a = int(input())
mx = 1

for i in range(2,a):
    j=2
    while i**j <= a:
        mx = max(i**j,mx)
        j+=1

print(mx)