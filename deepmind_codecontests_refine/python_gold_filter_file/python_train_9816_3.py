n, q = map(int, input().split())
A = [i for i in range(1, n + 1)]

prefix = [0] * (n + 1)
prefix[0] = A[0]
for i in range(1, n):
    prefix[i] = prefix[i - 1] + A[i]
    
used0 = A[max(0, n - 15)::]
used0.sort()
used_d = {}
for i in used0:
    used_d[i] = 0
 
fact = [0] * n
fact[-1] = 1
for i in range(n - 2, max(-1, n - 16), -1):
    fact[i] = fact[i + 1] * (n - 1 - i)

number = 1
#print(fact)

def permutation_by_number(number):
    for i in range(max(0, n - 15), n):
        position = max(0, (number - 1) // fact[i])
        #print(position)
        counter = 0
        for j in used_d:
            if position == counter and not used_d[j]:
                A[i] = j
                used_d[j] = 1
                break
            if not used_d[j]:
                counter += 1
        number -= position * fact[i] 
    for i in range(max(0, n - 15), n):
        prefix[i] = prefix[i - 1] + A[i]
            
for i in range(q):
    #print(prefix, A, number)
    t = list(map(int, input().split()))   
    if t[0] == 1:
        l, r = t[1], t[2]
        print(prefix[r - 1] - prefix[l - 2])
    else:
        for j in used_d:
            used_d[j] = 0
        x = t[1]
        number += x
        permutation_by_number(number)
        
        
        
        
        
        
        
        
