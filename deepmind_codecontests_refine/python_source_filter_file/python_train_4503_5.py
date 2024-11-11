def rn():
    a = int(input())
    return a


def rl():
    a = list(map(int, input().split()))
    return a


#for _ in range(int(input())):
#n = rn()
[a,b,c,d] = rl()
C = b-a+1
R = c-b+1
Per = min(R,c)
mul = [Per for i in range(R+C)]
for i in range(1,Per):
    mul[i] = i
    mul[-i] = i
curr = a+b
mul2 = [0 for i in range(R+C)]
ans = 0
for i in range(1,R+C):
    mul2[i] = max(0,min(curr-1,d)-c+1)
    ans += (mul[i]*mul2[i])
    curr += 1
print(ans)
