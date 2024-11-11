# cook your dish here
n, m = map(int, input().split())
Ene = set()
Pol = set()

for i in range(n):
    Pol.add(input())
for i in range(m):
    Ene.add(input())
comm_ele = 0
for num in Pol:
    if num in Ene:
        comm_ele += 1
if n>m:
    print("YES")
elif n<m:
    print("NO")
else:
    if comm_ele == n:
        print("NO") if n%2 ==0 else print("YES")
    elif comm_ele == 0:
        print("NO")
    else:
        print("YES") if comm_ele%2 == n%2 else print("NO")
    