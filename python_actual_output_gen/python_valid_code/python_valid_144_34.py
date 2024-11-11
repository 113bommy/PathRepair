i = lambda: map(int, input().split())   
n, c =  i()
z = list(i())
a = k = 0
for b in z:  k = 1 + k*(b-a <= c); b = a
print(k)
