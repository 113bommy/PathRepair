n = int(input())
s = str(input())
a = []
for i in range(1,n+1):
    if n % i == 0:
        a.append(i)
for i in a:
    temp = ""
    for j in range(i):
        temp += str(s[j])
    s = s.replace(temp, temp[::-1],1)
    temp,temp[::-1]
print(s)