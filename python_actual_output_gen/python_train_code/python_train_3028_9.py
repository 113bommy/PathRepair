n , m = input().split()
n = int(n)
m =  int(m)
count = 0
ans = 0
while m>n:
    if n%2 ==1:
        m += 1
        count += 1
    else:
        m /= 2
        count += 1
ans = (count + n - m)
 
print(ans)