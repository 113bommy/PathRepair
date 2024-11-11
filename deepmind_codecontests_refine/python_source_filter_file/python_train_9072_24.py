n = int(input())
t = n//2+1
for i in range(1,t+1):
    print(i,'1')
if n % 2:
    for i in range(2,t+1):
        print(t,i)
else:
    for i in range(2, t):
        print(t,i)