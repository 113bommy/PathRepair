from operator import itemgetter
#int(input())
#map(int,input().split())
#[list(map(int,input().split())) for i in range(q)]
#print("YES" * ans + "NO" * (1-ans))
n,k =  map(int,input().split())
si = list(map(int,input().split()))
num = 10**5 * 2 + 1
ai = [0] * num
for i in range(n):
    ai[si[i]] += 1
num3 = num
num = max(ai) + 1
ai2 = [[] for i in range(num)]
for i in range(num3):
    if ai[i] != 0:
        ai2[ai[i]] += [[i,1,ai[i]]]
i = num-1
while k > 0:
    for j in ai2[i]:
        if k == 0:
            break
        num2 =  j[2] * j[1] // (j[1]+1)
        ai2[num2] += [[j[0],j[1]+1,j[2]]]
        print(j[0],end=" ")
        k -= 1
    i -= 1
    
