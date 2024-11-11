a,v = map(int, input().split())
b,w = map(int, input().split())
t=int(input())

rev = abs(v-w)
if rev*t >= abs(b-a):
    print("YES")
else:
    print("NO")