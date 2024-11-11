n = int(input ())
a = (list(map(int,input().split())))
a.reverse()
print(a)
a_set = set()
for i in range(0,len(a)):
    if not(a[i] in a_set) :
        a_set.add(a[i])
        max_a=a[i]
print(max_a)        
