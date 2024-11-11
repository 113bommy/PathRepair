n = int(input())

for i in range(1,n+1):
    if n <= 5:
        print("-1")
        break
    if i < 5:
        print("1",i)
    else:
        print("2",i)
for i in range(1,n):
    print(i,i+1)