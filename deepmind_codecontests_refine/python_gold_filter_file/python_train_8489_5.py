a = [ int(x) for x in input().split()]
n = a[0]
k = a[1]
t = a[2]
t = t / 100
s = int(n * k * t)
count = 0
output = []
while s > 0:
    if s > k:
        
        output.append(k)
        
    else:
        output.append(s)
        
    count += 1
    s = s - k
while count < n:
    output.append(0)
    count += 1
for x in output:
    print(x, end = " ")
