n = int(input())
s = str(input())
pos = 0
for i in range(0,n-1):
    if s[i] > s[i+1]:
        pos = i
        break
print(s[0:pos] + s[pos+1:])
