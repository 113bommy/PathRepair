
def pretty_print_list(a):
    for aa in a:
        print(*aa)


        
m, n = map(int, input().split())
a = [[i for i in map(int, input().split())] for _ in range(m)]

#pretty_print_list(a)

if m % 2:
    print(m)
    exit()
'''    
for i in range(m):
    print(i, a[i])
    print(-i, a[m - i - 1])
'''
    
#exit()
m2 = m
while not m2 % 2:
    m2 //= 2
    for i in range(m2):
        #print(a[i], a[-i])
        #print(i, a[i])
        #if a[i] != a[-i]:
        if a[i] != a[2 * m2 - i - 1]:
            print(m2 * 2)
            exit()
print(1)

