le=int((input().split())[1])
s=list(map(int, input().split()))
s.sort()
s.insert(0,-s[1])
s.append(le+le-s[-1])

diff=[s[i+1]-s[i] for i in range(len(s)-1)]

d=max(diff)/2
print(d)