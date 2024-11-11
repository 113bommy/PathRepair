#f = open('Text.txt',"r")
n = int(input())
res = 0

for x in range(3, n+1):
    res += 1*(x-2)*(x-1)

print(res)
