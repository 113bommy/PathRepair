d = int(input())
n = int(input())
s = input()
temp = s.split()
days = [int(i) for i in temp]

result = 0

for i in range(1,n):
    result += (d - days[i])
print(result)
