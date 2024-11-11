lines = input().split()
c = int(lines[0])
v0 = int(lines[0])
v1 = int(lines[0])
a = int(lines[0])
l = int(lines[0])
r = 0
days = 0

while r<c:
    if r!=0:
        r-=l
    r+=v0
    v0+=a
    if v0>v1:
        v0=v1
    days+=1

print(days)