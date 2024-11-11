x=int(input())
a=0
for i in range(300):
    for j in range(11):
        if i**j>x: break
        if a<i**j: a=i**j   
print(a)