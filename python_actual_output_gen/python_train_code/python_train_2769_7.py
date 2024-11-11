n = int(input())
total = 0
s = input().split()
s = [int(x) for x in s]
s.sort()
for i in range(0,n-1):
    total +=(i+2)*s[i]
total +=n*s[0]
print(total)
