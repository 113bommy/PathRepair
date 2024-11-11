n = int(input())
a = input().split(' ')
counter = 1
best = 0
for i in range(n):
    if(int(a[i-1]) <= int(a[i])):
       counter += 1
    else:    
        counter = 1
    if(best < counter):
            best = counter
print(best)        
