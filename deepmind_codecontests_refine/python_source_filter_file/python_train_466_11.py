def LM():
    return list(map(int,input().split()))

M = LM()
W = LM()
result = 0
for i in range(5):
    result += max(0.3*500*(i+1),(1-M[i]*1/250)*500*(i+1)-50*W[i])
hs, hw = map(int,input().split())
result += (100*hs - 50*hw)
print(result) 