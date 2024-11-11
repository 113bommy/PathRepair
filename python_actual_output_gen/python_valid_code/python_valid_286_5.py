s = input()
rs = "a"
t = 0
for i in s :
    if i > rs:
        rs = i
        t = 1
    if i == rs:
        t+=1
ans = ""
for i in range(t - 1):
    ans+=rs
print(ans)