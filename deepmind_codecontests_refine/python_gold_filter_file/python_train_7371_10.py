s = int(input())
A = [s]
ans = 1
while True:
    ans +=1
    s = (s/2 if s%2==0 else 3*s+1)
    if s in A:
        break
    A.append(s)

print(ans)