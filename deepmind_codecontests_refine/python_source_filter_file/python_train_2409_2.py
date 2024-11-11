n=int(input())
a=[int(x) for x in input().split()]
v=max(a)
a.append(10**100)
counter=0
prev=10**100
max_counter=0
for item in a:
    if item==v:
        counter+=1
    else:
        if counter>max_counter:
            max_counter=counter
            counter=0

print(max_counter)
