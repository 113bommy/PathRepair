N=int(input())
P=list(map(float,input().split()))

NOW=[1]

for i in range(N):
    NEXT=[0]*(i+2)

    for j in range(i+1):
        NEXT[j]+=NOW[j]*(1-P[i])
        NEXT[j+1]+=NOW[j]*P[i]

    NOW=NEXT
    #print(NOW)

print(sum(NOW[1+N//2:]))