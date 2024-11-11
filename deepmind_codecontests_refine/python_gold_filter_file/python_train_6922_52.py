a = input()
b = int(a.split()[1])
a = int(a.split()[0])
k = input()
m = int(k.split()[1]) 
k = int(k.split()[0])

a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))


n1 = a1[0:k]
n2 = a2[-m:]

if n1[-1] >= n2[0]:
    print("NO")
else:
    print("YES")

