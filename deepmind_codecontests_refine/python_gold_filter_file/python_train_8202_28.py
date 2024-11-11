n = int(input())
y = 0
for i in range(1,int(n**0.5)+1):
    if (n-i)%i == 0 and n-i > i**2:
        y += (n-i)//i
print(y)
