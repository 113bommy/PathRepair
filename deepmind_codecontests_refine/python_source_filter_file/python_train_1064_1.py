import math
import fractions

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    # divisors.sort()
    return divisors

def ValueToBits(x,digit):
    res = [0 for i in range(digit)]
    now = x
    for i in range(digit):
        res[i]=now%2
        now = now >> 1
    return res

def BitsToValue(arr):
    n = len(arr)
    ans = 0
    for i in range(n):
        ans+= arr[i] * 2**i
    return ans

def ValueToArray10(x, digit):
    ans = [0 for i in range(digit)]
    now = x
    for i in range(digit):
        ans[digit-i-1] = now%10
        now = now //10
    return ans

'''
def cmb(n, r, p):
    if (r < 0) or (n < r):
        return 0
    r = min(r, n - r)
    return fact[n] * factinv[r] * factinv[n-r] % p

p = 10 ** 9 + 7
N = 10 ** 6 + 2
fact = [1, 1]  # fact[n] = (n! mod p)
factinv = [1, 1]  # factinv[n] = ((n!)^(-1) mod p)
inv = [0, 1]  # factinv 計算用

for i in range(2, N + 1):
    fact.append((fact[-1] * i) % p)
    inv.append((-inv[p % i] * (p // i)) % p)
    factinv.append((factinv[-1] * inv[-1]) % p)
'''


#a = list(map(int, input().split()))

n = int(input())
nb = [[] for i in range(n)]
nbe = [[] for i in range(n)]
es = []

for i in range(n-1):
    a,b = list(map(int, input().split()))
    a -= 1
    b -= 1
    es.append([a,b])
    nb[a].append(b)
    nb[b].append(a)
    nbe[a].append(i)
    nbe[b].append(i)

start=-1
for i in range(n):
    if(len(nb[i])==1):
        start=i
        break
    
queue=[start]
done=0
checked=[0 for i in range(n)]
checked[start] = 1
u = -1
v = -1
w = -1

while(True):
    #print(queue,done)
    if(len(queue)==done):
        #print("b")
        break
    else:
        
        now = queue[done]
        nownb = nb[now]
        #print("a",now,nownb,done)
        if(len(nownb)<=2):
            for j in range(len(nownb)):
                if(checked[nownb[j]]==0):
                    queue.append(nownb[j])
                    checked[nownb[j]]=1
            done+=1
        else:
            u = nbe[now][0]
            v = nbe[now][1]
            w = nbe[now][2]
            break
        
#print(u,v,w)
print(checked)
ans = [0 for i in range(n-1)]
now = 3

if(u!=-1):
    for i in range(n-1):
        if(i==u):
            print(0)
        elif(i==v):
            print(1)
        elif(i==w):
            print(2)
        else:
            print(now)
            now+=1

else:
    for i in range(n-1):
        print(i)










