a = ["2"] * 1000100
a[1] = "1"
for i in range(2, 1000010):
    if a[i] == "2":
        for j in range(i * i, 1000010, i):
            a[j] = "1"

# print(a[0:100])
n = int(input())
if n <= 2:
    print(1)
    print(' '.join(["1"] * n))
else:    
    print(2)
    print(' '.join(a[2:n + 2]))
