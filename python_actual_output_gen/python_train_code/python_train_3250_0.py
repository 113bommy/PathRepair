n, k = map(int , input().split())
pas=[]
for i in range(n):
    s = len(str(input()))
    pas.append(s)
password = len(str(input()))
pas.sort()
x = pas.index(password) + 1
pas = pas[::-1]
y = len(pas) - pas.index(password)
if x>k:
    a = 5*(x//k) + x%k
else:
    a = x
if y>k:
    b = 5*((y-1)//k) +  y
else:
    b = y
print(a,b)