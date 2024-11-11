n = input()
n = int(n)
p = input().split()
result = 0.0
for i in p:
    result+=(2/n)*(int(i)/100)
print(result*100)

