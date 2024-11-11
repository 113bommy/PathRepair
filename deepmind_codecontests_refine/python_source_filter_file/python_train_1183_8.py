
def point(s:int):
     print(s, " ", s)

t = list(map(int, input().split()))

n, k = t[0], t[1]

#  список размерностей квадрата
s = list(map(int, input().split()))
s.sort()

if k > len(s):
    print(-1)
else:
    for i in range(len(s)):
        if i == k-1: 
           point(s[-i]) 