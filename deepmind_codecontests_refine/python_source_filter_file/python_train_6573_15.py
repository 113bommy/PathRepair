
n, k = map(int, input().split())
candy = list(map(int, input().split()))
dicttotal = dict.fromkeys(range(k), 0)
answer = 0
     
for i in range (n) :
    dicttotal[candy[i] % k] += 1 
     
    
for i in range ((k + 1) // 2) :
    if i == 0 :
        answer += dicttotal[0]
        continue
    if dicttotal[i] <= dicttotal[k - i] :
        answer += dicttotal[i] 
    else :
        answer += dicttotal[k - i]
          
if k % 2 == 0 :    
    answer += dicttotal[k / 2] // 2
        
print (answer * 2)
