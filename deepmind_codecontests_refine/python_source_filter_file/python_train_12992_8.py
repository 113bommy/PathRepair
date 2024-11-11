S = input()
T = input()

len0 = len(S)
S = S * ((len(T) + len(S) - 1) // len(S) * 2)

MOD = 10 * 16 + 61
base = 26

hashS = [0]
hashT = 0
for s in S :
    hashS.append((hashS[-1] * base + ord(s) - 97) % MOD)
for t in T :
    hashT = (hashT * base + ord(t) - 97) % MOD

ok = [False] * len0
for i in range(len0) :
    if (hashS[i+len(T)] - hashS[i] * pow(base, len(T), MOD)) % MOD == hashT :
        ok[i] = True

def solve() :
    ret = 0
    visited = [-1]*len0
    for i in range(len0) :
        if ok[i] and visited[i] == -1 :
            j = i
            count = 0
            while ok[j] :
                if visited[j] != -1 :
                    count += visited[j]
                    break
                    
                count += 1
                visited[j] = 1
                j = (j+len(T))%len0
                if j == i :
                    return -1
            visited[i] = count
            ret = max(ret, count)
    return ret
        
print(solve())