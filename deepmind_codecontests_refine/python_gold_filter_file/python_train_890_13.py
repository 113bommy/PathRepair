n,m,z = map(int, input().split())

list_n = [x*n for x in range(1,(z//n)+1)]
list_m = [x*m for x in range(1,(z//m)+1)]
count = 0

for item in list_m:
    if item in list_n:
        count+=1 
        
print(count)