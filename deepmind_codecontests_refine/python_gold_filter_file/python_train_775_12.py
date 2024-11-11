k = input()
e = ' '
b = ''
l = len(k)
array = [0 for i in range(4)]
c = 0
c1 = 0
a = 0

for i in range(l):
    if(k[i] == e):
        c = c + 1
for i in range(l):
    if(k[i] != e):
        b = b + k[i]
    else:
        array[a] = int(b)
        b = ''
        a = a + 1
    c1 = c1 + 1
    if(c1 == l):
        array[a] = int(b)
    
n1 = array[0]
n2 = array[1]
k1 = array[2]
k2 = array[3]


supp_1 = n1
supp_2 = n2

if((supp_1) > supp_2):
    print("First")
else:
    print("Second")
