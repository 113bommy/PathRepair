n=int(input())
l=[4,7,47,74,44,77,444,447,474,477,777,774,774]
for i in l:
    if n%i==0:
        print("YES")
        exit()
print("NO")