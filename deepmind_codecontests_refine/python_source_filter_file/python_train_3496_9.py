n, k = input().split()

k = int(k)
current = len(n) - 1

zeros = 0
ans = 0
done = 0

while current >= 0:
   
    if zeros == k :
        print(ans)
        done = 1
        break
    if n[current] == "0":
        current -= 1
        zeros += 1
    else:
        n = n[:current] + n[current+1:]
        current -= 1
        ans += 1
        
if done == 0:
    ans += zeros - 1
    
print(ans)
    
    
    