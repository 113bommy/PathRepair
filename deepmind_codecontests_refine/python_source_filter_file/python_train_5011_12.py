X = {"R","G","B"}
def comp(a,b):
    x = {a,b}
    t = list(X^x)
    return t[0]

N = int(input())
S = [i for i in input()]
if(N == 1):
    print(0)
    print(S)
    exit()
count = 0
for i in range(N-2):
    if(S[i] == S[i+1]):
        S[i+1] = comp(S[i],S[i+2])
        count+=1
if(S[-1] == S[-2]):
    count+=1
    S[-1] = comp(S[-2],S[-2])
print(count)
print("".join(S))
