a = (input())
n, m = a.split()
n = int(n)
m = int(m)
l = dict()
for i in range(n):
    string = input()
    s = string.split()
    l[s[1]] = s[0]
print(l)
for i in range(m):
    string = input()
    s = string.split()
    print(s[0] +" "+s[1][0:-1]+"; #"+l[s[1][0:-1]])