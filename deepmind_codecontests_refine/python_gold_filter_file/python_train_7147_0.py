n, k = [int(x) for x in input().split()]
lis = [int(x) for x in input().split()]
taken = [int(x) for x in input().split()]

best_start_index = -1
best_start = 0
current_start = 0
current_total_with = 0
current_total_without = 0
for i in range(k):
    current_total_with += lis[i]
    if taken[i] == 1:
        current_total_without += lis[i]
best_start_index = 0
best_start = current_total_with - current_total_without
#print(best_start)
for i in range(1,n-k+1):
    current_total_with -= lis[i-1]
    current_total_with += lis[i+k-1]
    if taken[i-1] == 1:
        current_total_without -= lis[i-1]
    if taken[i+k-1]:
        current_total_without += lis[i+k-1]
    if best_start < current_total_with - current_total_without:
        best_start = current_total_with-current_total_without
        best_start_index = i
    #print("t",i,current_total_with,current_total_without)
    #print("temp",best_start)   
i = 0
total = 0
#print(best_start_index)
while i<n:
    if i>=best_start_index and i<best_start_index+k:
        total += lis[i]
    elif taken[i]:
        total += lis[i]
    i+=1
    
print(total)
        
        
