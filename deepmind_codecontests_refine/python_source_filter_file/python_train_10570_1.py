n = int(input())
a = list(map(int, input().split()))
s = sum(a)
t = 0
a.sort(reverse = True)
for i in a :
    t += i
    s -= i
    if(t > s) :
        break

print(t - s + 1)
