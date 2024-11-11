n = int(input())
a = list(map(int, input().split()))
even_lst = []
odd_lst = []
for i in range(n):
    if(a[i] % 2 == 0):
        even_lst.append(a[i])
    else:
        odd_lst.append(a[i])

if(len(even_lst) > len(odd_lst)):
    print(a.index(odd_lst[0])+1)
else:
    print(a.index(even_lst[0])+1)
