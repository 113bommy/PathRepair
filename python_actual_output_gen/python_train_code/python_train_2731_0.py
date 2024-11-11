s = list(input())
k = int(input())
w = list(map(int,input().split()))
s = s+([chr(97+w.index(max(w)))]*k)
print(s)
c = 0 
j = 1
for i in s:
    c = c + w[ord(i)-97]*j
    j = j + 1
print(c)