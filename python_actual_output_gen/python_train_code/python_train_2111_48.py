n = int(input())
a = list(map(int, input().split()))
s = [0] * n
for i in range(n):
    s[a[i]-1] += i+1 
print(s) 