m,n = input().split(" ")
m,n = int(m), int(n)
if (m%2 ==1 and n%2 ==0) or (m%2 == 0 and n%2 == 1):
    output = int(m * n / 2)
else:
    output = int(m * n/2 -1) if int(m * n/2)%2 else int(m * n/2)
print(output)